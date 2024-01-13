//
// Created by Michael Yu on 1/12/2024
//

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

using namespace std;

class Point
{
public:
    Point(unsigned int numberOfFeatures);
    // ~Point();
    friend std::ostream &operator<<(std::ostream &os, const Point &point);
    float euclideanDistance(const Point &p1, const Point &p2) const;

public:
    vector<float> coords;
    string classType;
    unsigned int numberOfFeatures;
};

#endif // POINT_H
