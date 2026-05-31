
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
using namespace std;


void findCheapestFlight(int cityA, int cityB, int flights[][5], int numFlights) {
    int minCost = INT_MAX;
    int bestFlight = -1;

    // Iterate through all flights
    for (int i = 0; i < numFlights; i++) {
        if (flights[i][2] == cityA && flights[i][3] == cityB) { // Check origin and destination
            if (flights[i][1] < minCost) { // Check for minimum cost
                minCost = flights[i][1];
                bestFlight = flights[i][0];
            }
        }
    }

    // Print result
    if (bestFlight != -1) {
        cout << "Cheapest flight from city " << cityA << " to city " << cityB << ": Flight Number "
             << bestFlight << ", Cost: $" << minCost << endl;
    } else {
        cout << "No direct flight found from city " << cityA << " to city " << cityB << "." << endl;
    }
}

int main() {
    // Flight data in a 2D array
    // Each row represents: [Flight Number, Price, Origin, Destination, Link]
    int flights[16][5] = {
        {201, 80, 2, 10, 3},
        {202, 80, 10, 2, 0},
        {301, 50, 2, 4, 0},
        {302, 50, 4, 2, 5},
        {303, 40, 4, 8, 7},
        {304, 40, 8, 4, 9},
        {305, 120, 4, 9, 0},
        {306, 120, 9, 4, 13},
        {401, 40, 8, 7, 0},
        {402, 40, 7, 1, 0},
        {403, 80, 7, 1, 16},
        {404, 80, 1, 7, 0},
        {501, 80, 9, 3, 15},
        {502, 80, 3, 9, 0},
        {503, 140, 9, 1, 0},
        {504, 140, 1, 9, 0}
    };

    int numFlights = 16;

    // Test cases
    cout << "Test Case 1: CityA = 2 (Boston), CityB = 4 (Houston)" << endl;
    findCheapestFlight(2, 4, flights, numFlights);

    cout << "Test Case 2: CityA = 9 (Denver), CityB = 4 (Washington)" << endl;
    findCheapestFlight(9, 4, flights, numFlights);

    cout << "Test Case 3: CityA = 4 (New York), CityB = 2 (Atlanta)" << endl;
    findCheapestFlight(4, 2, flights, numFlights);

    return 0;
}
