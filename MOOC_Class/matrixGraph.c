#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex
typedef int WeightType
typedef char DataType

/* Edge Define */
typedef struct{
	Vertex V1, V2;
	WeightType Weight;
}ENode;
typedef ENode Edge;

/* Graph Node Define */
typedef struct{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
}GNode;
typedef GNode MGraph;

MGraph CreateGraph(int VertexNum)
{	/* Initialize Graph with VertexNum vertex but edge */
	Vertex V, W;
	MGraph* Graph;
	Graph = (MGraph *)malloc(sizeof(GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0; V<Graph->Nv; V++)
		for(W = 0; W<Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* Insert Edge <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* if it's UndirectedGraph, insert<V1, V2> */
	Graph->G[E->V2][E->V1] = E->Weight;
}

bool isEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W]<INFINITY ? true : false;
}

/* Visited[] is global variable, and initialized as false */
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{	/* from Vertex S to search Graph by BFS */
	Queue Q;
	Vertex V, W;

	Q = CreateQueue(MaxSize);
	Visit(S);
	Visited[S] = true;
	AddQ(Q, S);

	while(!isEmpty(Q)){
		V = DeleteQ(Q);
		for(W = 0; W < Graph->Nv; W++)
			if(!Visited[W] && isEdge(Graph, V, W)){
				Visit(W);
				Visited[W] = true;
				AddQ(Q, W);
			}
	}
}