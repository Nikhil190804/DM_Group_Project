// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;

int minimum_path = 2147483647;
//function to remove source vertex from vector
vector<int> remove_source_vertex(vector<vector<int>> graph, int s){
    vector<int> result;
    int source = s;
    int i=0;
    int graph_size = graph.size();
    while(i<graph_size){
        int difference = i-source;
        if(difference!=0){
            result.push_back(i);
        }
        else{
            if(i==source){
                //vertex found
                //dont push back
            }
            else{
                result.push_back(i);
            }
        }
        i++;
    }
    return result;
}

int find_minimum_path_weight(int path1,int path2){
    if(path1>path2){
        return path2;
    }
    else{
        return path1;
    }
}

int compute_current_path_weight();


// implementation of traveling Salesman Problem
int travllingSalesmanProblem(vector<vector<int>> graph, int s)
{
	// store all vertex apart from source vertex
    vector<int> not_sources = remove_source_vertex(graph,s);
	// store minimum weight Hamiltonian Cycle.
	do {
		// store current Path weight(cost)
		int current_pathweight = 0;
		// compute current path weight
		int k = s;
		for (int i = 0; i < not_sources.size(); i++) {
			current_pathweight += graph[k][not_sources[i]];
			k = not_sources[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
        minimum_path= find_minimum_path_weight(minimum_path,current_pathweight);

	} while (
		next_permutation(not_sources.begin(), not_sources.end())
        );

	return minimum_path;
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
	// matrix representation of graph
    vector<vector<int>> graph;
    //take graph as a input
    /*

    UNCOMMENT THIS TO USE FOR INPUT FUNCTION

    */
    //graph=handle_user_input();
	graph = { 
        { -1, 10, 15, 20 },
		{ 10, -1, 35, 25 },
		{ 15, 35, -1, 30 },
		{ 20, 25, 30, -1} 
    };
	int s = 0;
    int minimum_cost = travllingSalesmanProblem(graph,s);
	cout << "Minimum Cost is: " <<minimum_cost<< endl;
	return 0;
}
