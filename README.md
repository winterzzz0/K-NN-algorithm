# Regression K-NN Algorithm
## Implementation of Weighted Regression K-NN (K Nearest Neighbors) Improved by Normalization

### Description
This project is an implementation of the Regression K-NN (K Nearest Neighbors) algorithm. It is enhanced by **weighted distance calculations** and **normalization** of feature values to improve the accuracy of the predictions. The algorithm predicts the target value for a given test point by considering the closest **K** neighbors in the training data.

### Features
- **Weighted K-NN**: An improved version of K-NN that assigns weights based on the distance of neighbors.
- **Normalization**: Feature values are normalized to improve accuracy in distance calculations.
- **Regression Prediction**: Predicts a continuous ( Real values ) target value using regression.

### Example in the Main Function :
```cpp
vector<vector<double>> DataTraining = {
   {3.329020, 396.935231, 2.139362, 66951.489552},
   {6.962701, 272.208018, 1.147548, 67460.478731},
   {3.805400, 285.229773, 3.438257, 86297.783944},
   // ...
};
```
### Test Data Example :
```cpp
vector<double> TestData {2.11112, 21, 3.2213};
```
