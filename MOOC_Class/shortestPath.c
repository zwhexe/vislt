#include <stdio.h>
#include <stdlib.h>
#define MAX 500
#define INFINITY 10000

typedef struct ENode Edge;
struct ENode {
	int V1, V2;
	int Len;
	int Pay;
};

typedef struct AdjNode Adj;
struct AdjNode {
	int AdjV;
	int Len;
	int Pay;
	Adj* Next;
};

typedef struct GNode LGraph;
struct GNode {
	int Nv;
	int Ne;
	Adj G[MAX];
};

void InsertEdge(LGraph* LG, Edge* E)
{
    Adj *AV = (Adj *) malloc(sizeof(struct AdjNode));
    AV->AdjV = E->V2;
    AV->Len = E->Len;
    AV->Pay = E->Pay;
    AV->Next = LG->G[E->V1].Next;
    LG->G[E->V1].Next = AV;

    Adj *AW = (Adj *)malloc(sizeof(struct AdjNode));
    AW->AdjV = E->V1;
    AW->Len = E->Len;
    AW->Pay = E->Pay;
    AW->Next = LG->G[E->V2].Next;
    LG->G[E->V2].Next = AW;
}

LGraph* BuildGraph(int N, int M)
{
    LGraph *LG = (LGraph *)malloc(sizeof(struct GNode));
    LG->Nv = N;
    LG->Ne = M;
    for (int V = 0; V < N; V++){
        LG->G[V].AdjV = V;
        LG->G[V].Len = 0;
        LG->G[V].Pay = 0;
        LG->G[V].Next = NULL;
    }

    for (int i = 0; i < M; i++){
        Edge *E = (Edge *)malloc(sizeof(struct ENode));
        scanf("%d %d %d %d", &E->V1, &E->V2, &E->Len, &E->Pay);
        InsertEdge(LG, E);
    }

    return LG;
}

int FindMin(LGraph* LG, int collected[], int dist[])
{
    int minV, minDist = INFINITY;
    for(int V = 0; V < LG->Nv; V++){
        if(collected[V]==0 && dist[V] < minDist){
            minDist = dist[V];
            minV = V;
        }
    }
    if(minDist < INFINITY)
        return minV;
    else
        return -1;
}

void Dijkstra(LGraph* LG, int S, int D, int fee[], int dist[], int path[])
{   // Remember fee, dist, path all of them are based on S vertex!
    int collected[MAX] = {0}; collected[S] = 1;
    fee[S] = 0; dist[0] = 0; path[S] = S;
    Adj* AN = LG->G[S].Next;
    while(AN != NULL){
        dist[AN->AdjV] = AN->Len;
        fee[AN->AdjV] = AN->Pay;
        path[AN->AdjV] = S;
        AN = AN->Next;
    } // at first, only S in collected, but dist has value

    int minV, V, W;
    while(1){
        minV = FindMin(LG, collected, dist);
        if(minV < 0)
            break;
        /*  dist[minV] is not INFINITY, which can be sure
            start traverse LG->G[minV], update dist, fee, path */
        collected[minV] = 1;
        AN = LG->G[minV].Next;
        while(AN != NULL){
            if(collected[AN->AdjV] == 0){
                if((AN->Len+dist[minV]) < dist[AN->AdjV]){
                    dist[AN->AdjV] = AN->Len+dist[minV];
                    fee[AN->AdjV] = AN->Pay+fee[minV];
                    path[AN->AdjV] = minV;
                }
                else if ((AN->Len+dist[minV]) == dist[AN->AdjV])
                    if (AN->Pay + fee[minV] < fee[AN->AdjV]){
                        dist[AN->AdjV] = AN->Len+dist[minV];
                        fee[AN->AdjV] = AN->Pay+fee[minV];
                        path[AN->AdjV] = minV;
                    }
            }
            AN = AN->Next; // AN are vertex around minV, but not collected
        } 
    }
}

int main()
{
	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
    LGraph *LG = BuildGraph(N, M);

    // Adj *A = LG->G[0].Next;
    // while(A != NULL) 
    // {
    //     printf("%d %d %d\n", A->AdjV, A->Len, A->Pay);
    //     A = A->Next;
    // }

    int dist[MAX] = { INFINITY };
    int fee[MAX] = { INFINITY };
    int path[MAX] = { -1 };
    Dijkstra(LG, S, D, fee, dist, path);
    printf("%d %d\n", dist[D], fee[D]);

    return 0;
}