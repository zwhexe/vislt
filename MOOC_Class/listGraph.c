#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

/* Edge Define */
typedef struct ENode Edge;
struct ENode{
    Vertex V1, V2;  //edge link V1 & V2
    WeightType Weight;  //edge weight
};

/* Adjacent Node Define */
typedef struct Adjacent AdjNode;
struct Adjacent{
    Vertex AdjV;    // adjacent Vertex index
    WeightType Weight;  // edge weight
    AdjNode* next;   // to next adjacent Vertex
};

/* Vertex Head Node define */
typedef struct VNode{
    AdjNode* FirstEdge; // the head Vertex with first edge
    DataType Data;  // Vertex stored data
} AdjList[MaxVertexNum];    // number of adjacent for this Vertex

/* Graph Node define */
typedef struct GNode LGraph;
struct GNode{
    int Nv; // total Vertex node in the Graph
    int Ne; // total Edge in the Graph
    AdjList G;  // linked Graph
};

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph* Graph;
    /* Create Graph with VertextNum Vertex but no edge */
    Graph = (LGraph *)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V = 0; V < Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{   /* Create V2 to linke V1 */
    AdjNode *NewNode;
    NewNode = (AdjNode *)malloc(sizeof(struct Adjacent));
    NewNode->AdjV = E->V2; // NewNode is V2 of inserted Edge
    NewNode->Weight = E->Weight;
    /* insert V2 to V1 head */
    NewNode->next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    /* if UDG, linke V1 to V2 also */
    NewNode = (AdjNode *)malloc(sizeof(struct Adjacent));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    /* insert V1 to V2 head */
    NewNode->next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv); // read Vertex number
    Graph = CreateGraph(Nv);

    scanf("%d", &(Graph->Ne)); // read Edge number
    if(Graph->Ne != 0){  /* if edge existed */
        E = (Edge *)malloc(sizeof(struct ENode));
        for(i = 0; i<Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    for(V=0;V<Graph->Nv;V++)
        scanf("%c", &(Graph->G[V].Data));
    return Graph;
}

void Visit(Vertex V)
{
    printf("Now Visit Vertex %d\n", V);
}
/* last parameter is function pointer to pass function */
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{   /* From V to search Graph by DFS */
    AdjNode* W;
    Visit(V);
    Visit[V] = true;

    for(W=Graph->G[V].FirstEdge; W; W=W->next)
        if(!Visit[W->AdjV])
            DFS(Graph, W->AdjV, Visit);
}