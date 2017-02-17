//Vishalsingh Hajeri
//Data Structures and Analysis
//04/19/2016
//references:http://www.geeksforgeeks.org


#include <iostream>
#include <limits.h>
#include<fstream>

#define V 8
using namespace std;

int minDistance(double dist[], bool sptSet[])
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(double dist[], int n)
{
	cout << "Vertex   Distance from Source\n";
	for (int i = 0; i < V; i++)
		cout << i << "\t" << dist[i] << endl;
}


void dijkstra(double graph[V][V], int src)
{
	double dist[V];    

	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	
	dist[src] = 0;

	
	for (int count = 0; count < V - 1; count++)
	{
		
		int u = minDistance(dist, sptSet);

		
		sptSet[u] = true;

		
		for (int v = 0; v < V; v++)

			
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	
	printSolution(dist, V);
}


int main(int argc, char* argv[])
{
	double graph[8][8] = { 0 };
	int edge1,edge2;
	double wt;
	ifstream file;


	file.open(argv[1]);
	while (true)
	{
		file >> edge1 >> edge2 >> wt;
		if (file.eof())
			break;
		graph[edge1][edge2] = wt;
	}
	
	dijkstra(graph, 0);
	system("pause");
	return 0;
}