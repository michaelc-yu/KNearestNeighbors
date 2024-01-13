//
// Created by Michael Yu on 1/12/2024
//

#include "point.h"

#include <iostream>
#include <vector>

using namespace std;

class KNN
{
public:
    KNN(int k);
    ~KNN();
    int loadData(std::string& filename);
    void calcDistances(const Point &newpoint, vector<pair<float, string> > &result);
    string classify(vector<pair<float, string> > &distances);

public:
    vector<Point> centroids;
    int numNearestNeighbors;
};

