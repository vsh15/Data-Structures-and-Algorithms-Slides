//////////////////////////// Q6 - Dijkstra's Algorithm ///////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
/////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>


#define MAX_VAL (float)INT_MAX 

using namespace std;



void addEdge(vector<vector<float>> &adj, int v, int w, float weight)
{
	adj[v][w] = weight;
	adj[w][v] = weight;
}



int minDist(int V, vector<float> &distance, vector<bool> &visited)
{
	float min = MAX_VAL;
	int minIndex;

	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false && min >= distance[i])
		{
			min = distance[i];
			minIndex = i;
		}
	}

	return minIndex;
}


void dijkstra(int V, vector<vector<float>> &adj, int start)
{
	vector<float> distance(V, MAX_VAL);
	vector<bool> visited(V, false);

	distance[start] = 0;

	for (int i = 0; i < V - 1; i++)
	{
		int min = minDist(V, distance, visited);

		visited[min] = true;

		for (int j = 0; j < V; j++)
		{
			if (!visited[j] && adj[min][j] && distance[min] != MAX_VAL && distance[min] + adj[min][j] < distance[j])
				distance[j] = distance[min] + adj[min][j];
		}
	}

	ofstream output_file("out.txt");

	cout << "Distances of all nodes from the source, i.e. node-" << start << " : " << endl;
	output_file << "Distances of all nodes from the source, i.e. node-" << start << " : " << endl;
	for (int i = 0; i < V; i++)
	{
		cout << i << "  " << distance[i] << endl;
		output_file << i << "  " << distance[i] << endl;
	}
	cout << endl;
	output_file.close();
}



int main(int argc, char* argv[])
{
int V;
int numEdges, src, dest;
float weight;
int start, i;


ifstream file(argv[1]);

file >> V;
file >> numEdges;
vector<vector<float>> adj(V, vector<float>(V));

i = 0;
while (!file.eof())
{
	file >> src >> dest >> weight;
	if (i == 0)
	{
		start = src;
		i = 1;
	}
	addEdge(adj, src, dest, weight);
}
file.close();

dijkstra(V, adj, start);

system("pause");
return 0;
}