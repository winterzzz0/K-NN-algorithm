#include "KNNImplementation.h"

// Calculate the Euclidean distance between the two vectors (while ignoring the target (last col ))
double KNNImplementation::calculateDistanceEC(const vector<double> &temp , const vector<double> &temp2){
    
    double sumTheDifference {};
    double finalRes {};
    for(size_t  i {}; i<(temp.size()-1); i++){
            sumTheDifference  += pow((temp.at(i) - temp2.at(i)),2);
    }
	
    finalRes = sqrt(sumTheDifference );
    return finalRes;
}

//calculating the weight of each instance
double KNNImplementation::calculateWeight(const vector<double> &temp){
    if(temp.empty()){
         throw std::invalid_argument("Vector is Empty");
        return -1.0;
    }
    double lastIndex = temp.at(temp.size()-1);
    if(lastIndex == 0){
        lastIndex = 0.00000001;
    }
    return (1/pow(lastIndex,2));
}

//Part of calculating the average regression
double KNNImplementation::calculateAveragreReg(const vector<double> &vec){
    double weight = vec.at(vec.size()-1);
    double target = vec.at(vec.size() - 3);
    return (weight * target);
}

//Normalization of data training and the data test to improve accuracy 
void KNNImplementation::normalizing(vector<vector<double>> &vec, vector<double> &vec2){
	if(vec.empty()){
		cout<<"dataTraining is Empty";
		return;
	}
	for(size_t i {}; i<vec.at(0).size()-1; i++){
		double min {std::numeric_limits<double>::max()};
		double max {std::numeric_limits<double>::min()};
		for(size_t j {}; j<vec.size(); j++){
			if(vec.at(j).at(i) < min){
				min = vec.at(j).at(i);
			}
			if(vec.at(j).at(i) > max){
				max = vec.at(j).at(i);
			}
		}
		for(size_t j {}; j<vec.size(); j++){
			if(max == min){
				vec.at(j).at(i) = 0;
				continue;
			}
			double avg = (vec.at(j).at(i) - min)/(max - min);
			vec.at(j).at(i) = avg;
			
		}
		if(max == min){
				vec2.at(i) = 0;
				continue;
			}
		double avg2 = (vec2.at(i) - min)/(max-min);
		vec2.at(i) = avg2;
		
	}
	
	
}

//The actual implementation
double KNNImplementation::ImpKNN(vector<vector<double>> &dataTrainingVal, vector<double> appliedData , int k){
	
	normalizing(dataTrainingVal,appliedData);
    vector<vector<double>> lowestK {};
    for(size_t i {}; i<dataTrainingVal.size(); i++){
		double tempDistance ={calculateDistanceEC(dataTrainingVal.at(i), appliedData)};
        dataTrainingVal.at(i).push_back(tempDistance);
        dataTrainingVal.at(i).push_back(calculateWeight(dataTrainingVal.at(i)));
    }
    for(int i {}; i<k;i++){
        double lowest {std::numeric_limits<double>::max()};
        int index {-1};
        for(size_t j {}; j<dataTrainingVal.size(); j++){
            if(lowest >= dataTrainingVal.at(j).at(dataTrainingVal.at(j).size() -2)){
                lowest = dataTrainingVal.at(j).at(dataTrainingVal.at(j).size() -2);
                index = j;
            }
        }
        if(index != -1){
        lowestK.push_back(dataTrainingVal.at(index));
        dataTrainingVal.erase(dataTrainingVal.begin() + index);
        }
        
    }
    double res {};
    double weightSum {};
    for(size_t i {}; i<lowestK.size(); i++){
        res += calculateAveragreReg(lowestK.at(i));
        weightSum += lowestK.at(i).at(lowestK.at(i).size() - 1);
    }
    if(weightSum == 0.0){
        cout<<"weight sum is zero!";
        return 0.0;
    }
    return res / weightSum;
    
}


KNNImplementation::KNNImplementation()
{
    
}

KNNImplementation::~KNNImplementation()
{
}