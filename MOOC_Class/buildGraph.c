#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef int Weight;
typedef int DataType;

/* define Matrix Graph */
typedef struct MNode MGraph;
struct MNode {
	int Nv;
	int Ne;
	Weight G[MAX][MAX];
	DataType Data[MAX];
};

/* define Linklist Graph */
typedef struct AdjNode Adj;
struct AdjNode {
	int AdjV; // the index of Adj Node
	Weight W;
	Adj* Next;
};

typedef struct VNode {
	Adj* FirstNode;
	DataType Data;
} AdjList[MAX];

typedef struct LNode LGraph;
struct LNode {
	int Nv;
	int Ne;
	AdjList G; //an Array to store Vertex in G 
};

typedef struct ENode Edge;
struct ENode {
	int V1, V2;
	Weight W;
};


/* Build Matrix Graph */
MGraph* CreateMGraph(int N)
{
	MGraph* Gp;
	Gp = (MGraph*)malloc(sizeof(struct MNode));
	Gp->Nv = N;
	Gp->Ne = 0;
	for (int V = 0; V < Gp->Nv; V++) {
		for (int W = 0; W < Gp->Nv; W++)
			Gp->G[V][W] = 0;
	}
	return Gp;
}

void InsertMEdge(MGraph* Gp, Edge* E)
{
	Gp->G[E->V1][E->V2] = E->W;

	Gp->G[E->V2][E->V1] = E->W;
}

MGraph BuildGraph()
{
	MGraph Graph;
	
}

/* Build Linklist Graph */
LGraph* CreateLGraph(int N)
{
	int V;
	LGraph* Gp;
	Gp = (LGraph*)malloc(sizeof(struct LNode));
	Gp->Nv = N;
	Gp->Ne = 0;
	for (V = 0; V < Gp->Nv; V++)
		Gp->G[V].FirstNode = NULL;
	return Gp;
}

void InsertLEdge(LGraph* Gp, Edge* E)
{
	Adj* NewNode;
	NewNode = (Adj*)malloc(sizeof(struct AdjNode));
	NewNode->AdjV = E->V2;
	NewNode->W = E->W;
	NewNode->Next = Gp->G[E->V1].FirstNode;
	Gp->G[E->V1].FirstNode = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;

}