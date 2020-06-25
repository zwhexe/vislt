#include <stdio.h>
#include <stdlib.h>
#define MAX 100
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



typedef struct QNode Queue;
struct QNode {
    Vertex *Front;
    Vertex *Rear;
};

void InsertEdge(LGraph* LG, Edge* E)
{
    Vertex *V = (Vertex *)malloc(sizeof(struct VNode));
    V->Ind = E->V2;
    V->Weight = E->Weight;
    V->Next = LG->G[E->V1].Next;
    LG->G[E->V1].Next = V;  
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
        InsertEdge(LG, E);
        free(E);
    }

    return LG;
}

void Enqueue(Queue* Q, Vertex* V)
{
    Q->Rear->Next = V;
    Q->Rear = V;
}

int Dequeue(Queue* Q)
{   
    if(Q->Front->Next == NULL)
        return -1;
    int V = Q->Front->Next->Ind;
    Vertex* tmp = Q->Front->Next;
    Q->Front->Next = Q->Front->Next->Next;
    if(tmp == Q->Rear)
        Q->Rear = Q->Front;
    free(tmp);
    return V;
}

int TopSort(LGraph* LG, Queue* Q, int* Indegree)
{
    int cntV = 0, V;
    int Earliest[MAX] = { 0 };
    Vertex* next = NULL;
    for(int i = 0; i < LG->Nv; i++){
        if(Indegree[i] == 0){
            Vertex* tmp = (Vertex *)malloc(sizeof(struct VNode));
            tmp->Ind = i;
            tmp->Weight = Earliest[i];
            tmp->Next = NULL;
            Enqueue(Q, tmp);
        }
    }
    while(Q->Front->Next != NULL){
        V = Dequeue(Q);
        cntV++; next = LG->G[V].Next;
        while(next != NULL){
            if(Earliest[V]+next->Weight > Earliest[next->Ind])
                Earliest[next->Ind] = Earliest[V]+next->Weight;
            if(--Indegree[next->Ind]==0){
                Vertex* tmp = (Vertex *)malloc(sizeof(struct VNode));
                tmp->Ind = next->Ind;
                tmp->Weight = Earliest[next->Ind];
                tmp->Next = NULL;
                Enqueue(Q, tmp);
            }
            next = next->Next;
        }
    }

    if(cntV != LG->Nv)
        return -1;
    else
        return Earliest[V];
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    LGraph* LG = BuildGraph(N, M);

    int Indegree[MAX] = { 0 };
    Vertex* V = NULL;
    for(int i = 0; i < N; i++){
        V = LG->G[i].Next;
        while(V != NULL){ //Indegree, not Outdegree
            Indegree[V->Ind] += 1;
            V = V->Next;
        }
    }

    Queue* Q = (Queue *)malloc(sizeof(struct QNode));
    Vertex* Head = (Vertex *)malloc(sizeof(struct VNode));
    Head->Ind = -1; Head->Weight = INFINITY;
    Q->Front = Head;
    Q->Rear = Head;
    Q->Rear->Next = NULL;

    int cnt = TopSort(LG, Q, Indegree);
    if(cnt < 0)
        printf("Impossible");
    else
        printf("%d\n", cnt);

    return 0;
}