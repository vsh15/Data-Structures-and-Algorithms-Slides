//////////////////////////// Q2-b - Kruskal Algorithm ////////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
/////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>
#include <iostream>

using namespace std;


struct Edge
{
	int src, dest;											
	float weight;
};


struct Graph
{

	int V; 														// number of vertices
	int E;														// number of edges

	struct Edge* edge;											// array of edges
};


struct Graph* createGraph(int V, int E)							// function to create a new graph and return its pointer
{
	// create new graph... graph gets a pointer and a memory equal to that required by struct Graph is allocated
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	// allocate memory equal to that required by struct Edge multiplied by number of edges in the graph
	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;
}


struct subset
{
	int parent;													// root of the element
	int rank;													// size of its subset	
};


int find(struct subset subsets[], int i)
{
	// find root and make root as parent of i (path compression)
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}


void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);								// find parents of both x and y
	int yroot = find(subsets, y);


	if (subsets[xroot].rank < subsets[yroot].rank)				// attach smaller subset to larger subset
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;							// attach smaller subset to larger subset

	
	else														// if both subsets are of equal size  
	{
		subsets[yroot].parent = xroot;							// attach y subset to x	subset
		subsets[xroot].rank++;									// increase rank of x subset
	}
}


int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}


void KruskalMST(struct Graph* graph)							// Code Reference : geeksforgeeks.com
{
	int V = graph->V;											// number of vertices
	struct Edge *result = new struct Edge[V];					// result array will store the resulting MST
	int e = 0;													// count number of edges included in the MST
	int i = 0;													// keeps track of edges visited
				
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);		// sort on the basis of edge weights

		struct subset *subsets =
		(struct subset*) malloc(V * sizeof(struct subset));		// subsets array to denote the parent and rank of each element

	
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;									// initialize parents as themselves
		subsets[v].rank = 0;									// initialize ranks as 0
	}

	
	while (e < V - 1)											// because there are V-1 edges in the MST
	{
	
		struct Edge next_edge = graph->edge[i++];				// next edge as per sorted order

		int x = find(subsets, next_edge.src);					// parent of source of the edge
		int y = find(subsets, next_edge.dest);					// parent of destination of the edge

	
		if (x != y)												// means that they are not in the same component, means that adding the edge will not form a cycle
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	
	}

	
	printf("Edges in the constructed MST\n");
	ofstream output_file("out.txt");
	output_file << "Edges in the constructed MST\n";

	for (i = 0; i < e; ++i)
	{
		printf("%d -- %d == %f\n", result[i].src, result[i].dest, result[i].weight);
		output_file << result[i].src << " -- " << result[i].dest << " = " << result[i].weight << endl;
	}

	output_file.close();

	return;
}


int main(int argc, char* argv[])
{
	string line;
	int i = 0;

	ifstream file(argv[1]);
	long int a, b;
	file >> a;
	file >> b;

	struct Graph* graph = createGraph(a, b);

	while (!file.eof())
	{
		long int node1 = 0, node2 = 0;
		float node3 = 0;
		getline(file, line);
		file >> node1 >> node2 >> node3;
		graph->edge[i].src = node1;
		graph->edge[i].dest = node2;
		graph->edge[i].weight = node3;
		i++;
	}
	file.close();

	clock_t start = std::clock();											// start the timer
	KruskalMST(graph);
	double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;		// calculate duration after implementation

	cout << "\nDuration: " << duration << endl;

	return 0;
}