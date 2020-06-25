#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define INFINITY 10000

typedef struct ENode Edge;
struct ENode {
    int V1, V2;
    int Weight;
};

typedef struct VNode Vertex;
struct VNode {
    int Ind;
    int Weight;
    Vertex* Next;
};

typedef struct GNode LGraph;
struct GNode {
    int Nv;
    int Ne;
    Vertex G[MAX];
};

void InsertEdge(LGraph* LG, Edge* E);

LGraph* BuildGraph(int N, int M);

int FindMin(LGraph* LG, int* dist, int* collect);

int Prim(LGraph* LG, int dist[]);


int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    LGraph* LG = BuildGraph(N, M);

    int dist[MAX] = { INFINITY };
    int budget = Prim(LG, dist);
    printf("%d\n", budget);

    return 0;
}


void InsertEdge(LGraph* LG, Edge* E)
{
    Vertex *V = (Vertex *)malloc(sizeof(struct VNode));
    V->Ind = E->V2;
    V->Weight = E->Weight;
    V->Next = LG->G[E->V1].Next;
    LG->G[E->V1].Next = V;

    Vertex *W = (Vertex *)malloc(sizeof(struct VNode));
    W->Ind = E->V1;
    W->Weight = E->Weight;
    W->Next = LG->G[E->V2].Next;
    LG->G[E->V2].Next = W;    
}

LGraph* BuildGraph(int N, int M)
{
    LGraph* LG = (LGraph *)malloc(sizeof(struct GNode));
    LG->Nv = N;
    LG->Ne = M;
    for(int i = 0; i < N; i++){
        LG->G[i].Ind = i;
        LG->G[i].Weight = 0;
        LG->G[i].Next = NULL;
    }

    for(int i = 0; i < M; i++){
        Edge* E = (Edge *)malloc(sizeof(struct ENode));
        scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
        E->V1--; E->V2--;
        InsertEdge(LG, E);
        free(E);
    }

    return LG;
}

int FindMin(LGraph* LG, int* dist, int* collect)
{
    int minV = -1, minD = INFINITY;
    for(int i = 0; i < LG->Nv; i++)
        if(collect[i] == 0 && dist[i] < minD){
            minV = i;
            minD = dist[i];
        }
    return minV;
}

int Prim(LGraph* LG, int* dist)
{
    int countV = 0;
    int budget = 0;
    int collect[MAX] = {0}; // MST collection
    int parent[MAX] = {-1}; // Tree presentation
    // Initialize dist[] with start from 0
    Vertex* V = LG->G[0].Next;
    while(V != NULL){
        dist[V->Ind] = V->Weight;
        V = V->Next;
    }
    /*  dist[V]==0 : V in the tree
        dist[V]==INIFINITY : V not connect tree
        0 < dist[V] < INFINITY : V connect tree */
    collect[0] = 1; dist[0] = 0; // collect 0
    countV ++;
    while(1){
        int minV = FindMin(LG, dist, collect);
        if(minV == -1)
            break;
        // collect minV
        budget += dist[minV]; countV++;
        collect[minV] = 1; dist[minV] = 0;
        Vertex* W = LG->G[minV].Next;
        // minV->W1->W2->...->Wn->NULL
        while(W != NULL){ // W is vertex around minV
            if(dist[W->Ind] != 0)  // W not in tree
                if(W->Weight < dist[W->Ind]) { // update dist[W]
                    dist[W->Ind] = W->Weight;
                    parent[W->Ind] = minV;
                }
            W = W->Next;
        }
    }

    if (countV < LG->Nv)
        return -1;
    else
        return budget;
}