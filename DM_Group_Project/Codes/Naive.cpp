
#include <bits/stdc++.h>
using namespace std;

int TSP(int n,int graph[][4], int s)
{

    vector<int> vertex;
    for (int i = 0; i < n; i++){
        if (i != s){
            vertex.push_back(i);
        }
    }

    int min_path = INT_MAX;
    while (next_permutation(vertex.begin(), vertex.end()))
    {

        int cost = 0;

        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            cost += graph[k][vertex[i]];
            k = vertex[i];
        }
        cost += graph[k][s];

        min_path = min(min_path, cost);
    };

    return min_path;
}

int main()
{
    int n = 4; // total number of cities;

    int graph[][n] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << TSP(n,graph, s) << endl;
    return 0;
}
