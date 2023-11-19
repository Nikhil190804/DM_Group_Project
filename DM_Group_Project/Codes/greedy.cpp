// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum
// cost path for all the paths
bool break_for_while(vector<vector<int> > tsp,int counter,int i){
	bool result = false;
	if(counter >=tsp[i].size() -1){
		result=true;
	}
	return result;
}

int findMinRoute(vector<vector<int> > tsp)
{
	int sum = 0;
	int counter = 0;
	int j = 0, i = 0;
	int min = 2147483647;
	map<int, int> visitedRouteList;

	// Starting from the 0th indexed
	// city i.e., the first city
	visitedRouteList[0] = 1;
	int route[tsp.size()];

	// Traverse the adjacency
	// matrix tsp[][]
	while (i < tsp.size() && j < tsp[i].size())
	{

		// Corner of the Matrix
		bool break_choice = break_for_while(tsp,counter,i);
		if(break_choice==true){
			break;
		}
		else{
			//pass
			;
		}
	
		// If this path is unvisited then
		// and if the cost is less then
		// update the cost
		if (j != i && (visitedRouteList[j] == 0))
		{
			if (tsp[i][j] < min)
			{
				min = tsp[i][j];
				route[counter] = j + 1;
			}
		}
		j++;

		// Check all paths from the
		// ith indexed city
		if (j == tsp[i].size())
		{
			sum += min;
			min = 2147483647;
			visitedRouteList[route[counter] - 1] = 1;
			j = 0;
			i = route[counter] - 1;
			counter++;
		}
	}

	// Update the ending city in array
	// from city which was last visited
	i = route[counter - 1] - 1;

	for (j = 0; j < tsp.size(); j++)
	{

		if ((i != j) && tsp[i][j] < min) 
		{
			min = tsp[i][j];
			route[counter] = j + 1;
		}
	}
	sum += min;

	// Started from the node where
	// we finished as well.
	return sum;
}



//function to take the graph as a input
vector<vector<int>> handle_user_input(){
    vector<vector<int>> result;
    int rows;
    int columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout<< "Now Enter the values of the Graph:"<<endl;
    for(int i=0;i<rows;i++){
        vector<int> nested_vector;
        for(int j=0;j<columns;j++){
            cout<<"Enter Value for graph["<<i<<"]["<<j<<"]: ";
            int element;
            cin>>element;
            nested_vector.push_back(element);
        }
        result.push_back(nested_vector);
    }
    return result;
}



// Driver Code
int main()
{
	vector<vector<int>> graph;
	// Input Matrix
	//take graph as a input
    /*

    UNCOMMENT THIS TO USE FOR INPUT FUNCTION

    */
    //graph=handle_user_input();
	graph = { 
		{ -1, 10, 15, 20 },
		{ 10, -1, 35, 25 },
		{ 15, 35, -1, 30 },
		{ 20, 25, 30, -1 } 
		};

	// Function Call
	int minimum_cost=findMinRoute(graph);
	cout << "Minimum Cost is: " <<minimum_cost<< endl;
}

// This code is contributed by grand_master.
