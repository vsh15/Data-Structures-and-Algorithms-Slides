//Vishalsingh Hajeri
//Data Structures and Analysis
//04/19/2016
//references:http://www.geeksforgeeks.org

#include<iostream>
#include<fstream>

using namespace std;


struct Edge
{
	int edge1;
	int edge2;
	double weight;
};


struct Graph
{
	int V;						
	int E;						

	struct Edge *edge;			
};

struct Graph *buildGraph(int v, int e)				
{
	
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = v;
	graph->E = e;

	
	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;
}

struct Subset
{
	int parent;			
	int rank;				
};



int find(struct Subset subsets[], int i)
{
	
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}



void unionOfVertices(struct Subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);							
	int yroot = find(subsets, y);

	if (subsets[xroot].rank > subsets[yroot].rank)
	{
		subsets[yroot].parent = xroot;						
	}
	else if (subsets[xroot].rank < subsets[yroot].rank)
	{
		subsets[xroot].parent = yroot;						
	}
	else												  
	{
		subsets[yroot].parent = xroot;						
		subsets[xroot].rank++;								
	}
}




int compareFunction(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}


void kruskalAlgo(struct Graph* graph)
{
	int V = graph->V;																//vertices
	struct Edge* result = (struct Edge*) malloc(V * sizeof(struct Edge));			
	int iterations = 0;																
	int edgesVisited = 0;															// tracks edges visited	

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareFunction);			// sort 

	struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset));	

	for (int i = 0; i < V; ++i)
	{
		subsets[i].parent = i;														
		subsets[i].rank = 0;													
	}

	while (iterations < V - 1)														
	{
		struct Edge nextEdge = graph->edge[edgesVisited++];							

		int parentOfedge1 = find(subsets, nextEdge.edge1);							
		int parentOfedge2 = find(subsets, nextEdge.edge2);								

		if (parentOfedge1 != parentOfedge2)	
		{
			result[iterations++] = nextEdge;

			unionOfVertices(subsets, parentOfedge1, parentOfedge2);
		}
	}

	printf("Edges in the Minimum Spanning Tree are: \n");
	for (int i = 0; i < iterations; ++i)
	cout<<result[i].edge1<<"-"<<result[i].edge2<<"= "<<result[i].weight<<endl;
	return;
}


int main(int args, char* argv[])
{
	int Vertexes; 
	int Edges; 
	int source, edge2ination;
	float wt;
	int e = 0;


	ifstream file(argv[1]);

	file >> Vertexes;
	file >> Edges;
	struct Graph* graph = buildGraph(Vertexes, Edges);

	while (!file.eof())
	{
		file >> source >> edge2ination >> wt;
		graph->edge[e].edge1 = source;
		graph->edge[e].edge2 = edge2ination;
		graph->edge[e].weight = wt;
		e++;
	}

	file.close();
	
	kruskalAlgo(graph);


	
	return 0;
}