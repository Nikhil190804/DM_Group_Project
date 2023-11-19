#include <iostream>
#include <vector>
#include <limits>
#include <map>

using namespace std;

void findMinRoute(const vector<vector<int>>& tsp) {
    int n = tsp.size();
    int sum = 0;
    vector<int> route(n, -1);
    map<int, bool> visited;

    int currentCity = 0; // Start from the first city

    for (int counter = 0; counter < n - 1; ++counter) {
        int nextCity = -1;
        int minCost = numeric_limits<int>::max();

        for (int j = 0; j < n; ++j) {
            if (j != currentCity && !visited[j] && tsp[currentCity][j] < minCost) {
                minCost = tsp[currentCity][j];
                nextCity = j;
            }
        }

        route[counter] = nextCity;
        sum += minCost;
        visited[nextCity] = true;
        currentCity = nextCity;
    }

    // Return to the starting city
    sum += tsp[currentCity][0];

    // Output the minimum cost and route
    cout << "Minimum Cost is: " << sum << endl;
}

int main() {
    // Input Matrix
    vector<vector<int>> tsp = {
        { -1, 10, 15, 20 },
        { 10, -1, 35, 25 },
        { 15, 35, -1, 30 },
        { 20, 25, 30, -1 }
    };

    // Function Call
    findMinRoute(tsp);

    return 0;
}
