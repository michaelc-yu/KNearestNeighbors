//
// Created by Michael Yu on 1/12/2024
//

#include "point.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

Point::Point(unsigned int numberOfFeatures) : coords(numberOfFeatures), numberOfFeatures(numberOfFeatures)
{
}

float Point::euclideanDistance(const Point &p1, const Point &p2) const {
    cout << p1 << endl;
    cout << p2 << endl;
    if (p1.numberOfFeatures != p2.numberOfFeatures) {
        throw invalid_argument("Points must have the same number of features");
    }
    double sum_of_squares = 0.0;
    for (size_t i = 0; i < p1.numberOfFeatures; ++i)
    {
        sum_of_squares += pow(p2.coords[i] - p1.coords[i], 2);
    }
    return sqrt(sum_of_squares);
}

    std::ostream &
    operator<<(std::ostream &os, const Point &point)
{
    os << "Coordinates: ";
    for (int i = 0; i < point.numberOfFeatures; i++)
    {
        os << point.coords[i] << " ";
    }
    os << "\nClass Type: " << point.classType;
    return os;
}

// Point::~Point() {

// }



