#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

/**
 * @class MiddleEarth
 * @brief Stores all information regarding the Middle Earth class.
 *
 *
 *
 */
class MiddleEarth {
public:
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
    void print();
    void printTable();
    float getDistance(const string& city1, const string& city2);
    vector<string> getItinerary(unsigned int length);

private:
    int num_city_names, xsize, ysize; /* @var X and Y size variables. */
    unordered_map<string, float> xpos, ypos; /* @var map to store X and Y positions of the cities. */
    vector<string> cities; /* @var Vector to store all cities */
    unordered_map<string, unordered_map<string, float>> distances; /* @var Map to store distances between two cities. */

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
