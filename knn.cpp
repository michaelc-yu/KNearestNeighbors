//
// Created by Michael Yu on 1/12/2024
//

#include "knn.hpp"
#include "point.h"

#include <fstream>
#include <sstream>
#include <unordered_map>

KNN::KNN(int k) : numNearestNeighbors(k)
{

}

KNN::~KNN()
{

}

int KNN::loadData(std::string& filename) {
    ifstream inputfile(filename);

    if (!inputfile)
    {
        cout << "Error opening the file." << endl;
        return -1;
    }

    std::string header;
    std::string value;
    unsigned int numberOfFeatures = 0;

    getline(inputfile, header);
    std::istringstream headerStream(header);

    while (getline(headerStream, value, ','))
    {
        numberOfFeatures++;
    }
    numberOfFeatures--; // the class doesn't count as a feature
    cout << "num features:" << numberOfFeatures << endl;


    std::vector<Point> dataset;

    string line;
    char comma;
    float feature;

    while (getline(inputfile, line))
    {
        std::istringstream lineStream(line);
        Point p(numberOfFeatures);

        for (int i = 0; i < numberOfFeatures; i++)
        {
            getline(lineStream, value, ',');
            // cout << "Value: " << value << endl;
            p.coords[i] = std::stof(value);
        }
        getline(lineStream, p.classType, ',');

        cout << p << endl;
        dataset.push_back(p);
    }
    cout << "we have " << dataset.size() << " points" << endl;
    centroids = dataset;
    return 0;
}

void KNN::calcDistances(const Point &newpoint, vector<pair<float, string> > &result) {
    for (int i = 0; i < this->centroids.size(); ++i) {
        float dist = newpoint.euclideanDistance(newpoint, this->centroids[i]);
        // cout << dist << endl;
        result.push_back(make_pair(dist, this->centroids[i].classType));
    }
}

string KNN::classify(vector<pair<float, string> > &distances) {
    cout << "in classify" << endl;
    unordered_map<string, int> classOccurrences;
    for (size_t i = 0; i < this->numNearestNeighbors; ++i)
    {
        cout << distances[i].second << endl;
        classOccurrences[distances[i].second]++;
    }
    auto maxElement = max_element(
        classOccurrences.begin(), classOccurrences.end(),
        [](const pair<const string, int> &pair1, const pair<const string, int> &pair2)
        {
            return pair1.second < pair2.second;
        });

    std::cout << "Key with the highest occurrence: " << maxElement->first << std::endl;
    std::cout << "Value: " << maxElement->second << std::endl;

    return maxElement->first;
}

int main() {
    string file = "data.txt";
    KNN k(5); // 5 nearest neighbors
    k.loadData(file);
    Point p(5);
    vector<pair<float, string> > distances;
    k.calcDistances(p, distances);
    sort(distances.begin(), distances.end());
    cout << "distances:" << endl;
    for (size_t i = 0; i < distances.size(); ++i) {
        cout << distances[i].first << " " << distances[i].second << endl;
    }
    string classType = k.classify(distances);
    cout << "Point \n" << p << " \nbelongs to class " << classType << endl;
    return 1;
}

