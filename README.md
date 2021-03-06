# Micro-LM
A plain C library for machine learning on edge devices. It requires configuration files produced by [`Desk-LM`](https://github.com/Edge-Learning-Machine/Desk-LM).

Micro-LM currently implements the following ML algorithms:

- `Linear SVM`
- `Decision Tree`
- `Random Forest`
- `K-NN`
- `TripleES`, Holt-Winters Triple Exponential Smoothing for time series

Each algorithm provides both classification and regression, for binary and multiclass problems. `SVM` supports only ordinal multiclass classification. `Holt-Winters Triple Exponential Smoothing` supports only regression.

We are extending the library to other algorithms, also unsupervised. Your voluntary contribution is welcome.

## Usage

The [`Micro-LM`](https://github.com/Edge-Learning-Machine/Micro-LM) files available in this repository  must be compiled together with the .c and .h files produced by [`Desk-LM`](https://github.com/Edge-Learning-Machine/Desk-LM), which performs model training and cross-validation, and creates .c and .h files that store the best model's parameters.

You can compile the code as an executable or as a static library, using gcc/g++ for a Microcontroller or a desktop (e.g., thorugh Eclipse CDT or Visual Studio Code).

Configuration must be performed in `ELM.h`, where the user has to specify some `#define`, such as:
- The algorithm: `SVM`, `DT`, `RF`, `KNN` or `TripleES`
- `DS_TEST`, if you want to test performance in a dataset, instead of doing one shot estimations. Used only by: knn, decisionTree, svm, randomForest.
- `REGRESSION`, if you want to perform a regression. Default is classification (no regression). Used only by: knn, decisionTree, svm, randomForest. TripleES performs only regression

`ELM.h` exposes the following functions:
- *`float* preprocess(float* X)`*, where X is the sample vector. It returns the pointer to the processed vector. Use that pointer for the classification / regression function.
- *`int (*pClassf)(float[] X_processed)`*, where X_processed is the sample vector. pClassf points to the classification function of the selected algorithm. It returns the value of the estimated class for the input.
- *`float (*pRegress)(float[] X_processed)`*, where X_processed is the sample vector. pRegress points to the regression function of the selected algorithm. It returns the estimated value for the given input.

- *`HW_TripleExpoSmoothing(int arrayD[], int vlen, double alpha, double beta, double gamma,int slen, int n_preds, double scaling_factor)`*, for Holt-Winters time series

`Test.h` exposes the following function:
- *`void RunTest()`*, for the whole dataset testing. The algorithm is automatically selected by setting the algorithm constant in `ELM.h` (see above). This function prints the accuracy rate on Console.  N.B. Preprocess is built in this function.

## Data type
float 32 data are used

## Algorithm template
Inside this repository there are `ExampleAlgoTemplate.h` and `ExampleAlgoTemplate.c`. 
Those files should be used as base schema to develop more Machine Learning Algorithm that are fully compatible to the ELM.h structure.


## License
This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/Edge-Learning-Machine/Micro-LM/blob/master/LICENSE.md) file for details

## Contributing
Please see [CONTRIBUTING.md](https://github.com/Edge-Learning-Machine/Desk-LM/blob/master/docs/CONTRIBUTING.md)

Credits:
- `Alessio Capello` for Random Forest implementation and refactoring;
- `Gabriele Campodonico` for TripleES implementation;
- `Laura Pisano` for TripleES implementation;

## Reference article for more infomation
F., Sakr, F., Bellotti, R., Berta, A., De Gloria, "Machine Learning on Mainstream Microcontrollers," Sensors 2020, 20, 2638.
https://www.mdpi.com/1424-8220/20/9/2638

## References
https://medium.com/open-machine-learning-course/open-machine-learning-course-topic-9-time-series-analysis-in-python-a270cb05e0b3
