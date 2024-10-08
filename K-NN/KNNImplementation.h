#ifndef _KNN_clTabCtrl
#define _KNN_
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using std::vector;
using std::string;
using std::cout;

class KNNImplementation
{
private:
    vector<vector<double>> dataTraining;
    double calculateDistanceEC(const vector<double> &temp , const vector<double> &temp2);
	double calculateWeight(const vector<double> &temp);
    double selectNeibhors();
    double calculateAveragreReg(const vector<double> &vec);
	void normalizing(vector<vector<double>> &vec, vector<double> &vec2);
    
public:
    
    double ImpKNN(vector<vector<double>> &dataTraining, vector<double> appliedData , int k);
    
    KNNImplementation();
    ~KNNImplementation();

};

#endif
