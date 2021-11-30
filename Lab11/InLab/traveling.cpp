//John Link, jwl9vq@virginia.edu, 11/28/21, traveling.cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth* me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
/**
 * @brief Main method to compute the shortest distance path through middle earth.
 *
 *
 * @return Exit code
 * @param argc Number of expected input parameters.
 * @param argv Character array of string input parameters.
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth* me = new MiddleEarth(width, height, num_cities, rand_seed);
    vector<string> dests = me->getItinerary(cities_to_visit);
    string start = dests[0];
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    pair<float, vector<string>> p(computeDistance(me, start, dests), dests);
    do{
        if(min(p.first, computeDistance(me, start, dests)) != p.first){
            p = pair<float, vector<string>>(computeDistance(me, start, dests), dests);
        }
    } while(next_permutation(dests.begin(), dests.end()));
    dests = p.second;
    cout << "Minimum path has distance ";
    cout << computeDistance(me, start, dests) << ": ";
    printRoute(start, dests);
    delete me;
    return 0;
}

/**
 * @brief Computes the distance between all nodes in a path
 *
 * Traverses through the dists vector and sums up the distances between all cities.
 *
 * @return Total trip distance
 * @param me A middle earth object which stores the map data.
 * @param start The beginning city.
 * @param dests All cities to be visited.
 */
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth* me, const string& start, vector<string> dests) {
    float dist = me->getDistance(start, dests[0]);
    for(int x = 0; x < dests.size() - 1; x++){
        dist += me->getDistance(dests[x], dests[x+1]);
    }
    dist += me->getDistance(dests[dests.size() - 1], start);
    return dist;
}


/**
 * @brief Prints the final order of the Itinerary.
 *
 * Traverses through the dists vector and prints each city out in its respective order..
 *
 * @return void
 * @param start The beginning city.
 * @param dests All cities to be visited.
 */
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    cout << start << " -> ";
    for(int x = 0; x < dests.size(); x++){
        cout << dests[x] << " -> ";
    }
    cout << start << endl;
}
