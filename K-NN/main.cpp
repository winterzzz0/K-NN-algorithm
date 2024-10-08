#include <iostream> 
#include "KNNImplementation.h"

int main() {
    KNNImplementation KNN{};

    vector<vector<double>> DataTraining = { // last column as the target
        { 3.329020, 396.935231, 2.139362, 66951.489552 },
		{ 6.962701, 272.208018, 1.147548, 67460.478731 },
		{ 3.805400, 285.229773, 3.438257, 86297.783944 },
		{ 5.680612, 242.393458, 3.010716, 94855.512998 },
		{ 5.920393, 61.438607, 1.205915, 94354.321213 },
		{ 2.663690, 98.551142, 2.114586, 88993.777293 },
};

    vector<double> TestData {2.11112, 21, 3.2213};

    
    cout <<"The predicted is : " << KNN.ImpKNN(DataTraining, TestData, 2) << std::endl;

    return 0; 
}
