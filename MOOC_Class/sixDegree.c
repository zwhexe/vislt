#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct ENode Edge;
struct ENode {
    int V1;
    int V2;
    int Weight;
};

typedef struct MNode MGraph;
struct MNode {
    int Nv;
    int Ne;
    int G[MAX][MAX];
};

typedef struct Node QNode;
struct Node {
    int V;
    int level;
    QNode* next;
};

typedef struct QList Queue;
struct QList {
    QNode* front;
    QNode* rear;
};

Queue* initQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(struct QList));
    Q->front = Q->rear = (QNode*)malloc(sizeof(struct Node));
    Q->front->V = -1;
    Q->front->next = NULL;
    return Q;
}

void Enqueue(Queue* Q, int V, int level)
{
    QNode* q = (QNode*)malloc(sizeof(QNode));
    q->V = V;
    q->level = level;
    q->next = NULL;
    Q->rear->next = q;
    Q->rear = q;
}

int* Dequeue(Queue* Q)
{
    QNode* q = Q->front->next;
    int* arr = (int*)malloc(2 * sizeof(int));
    arr[0] = q->V;
    arr[1] = q->level;
    if (q == Q->rear) {
        Q->rear = Q->front;
        Q->front->next = NULL;
        free(q);
    }
    else {
        Q->front->next = q->next;
        free(q);
    }
    return arr;
}

MGraph* CreateMGraph(int N)
{
    MGraph* MG;
    MG = (MGraph*)malloc(sizeof(struct MNode));
    MG->Nv = N;
    MG->Ne = 0;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            MG->G[i][j] = 0;
    return MG;
}

void InsertEdge(MGraph* MG, Edge* E)
{
    MG->Ne++;
    MG->G[E->V1][E->V2] = E->Weight;
    MG->G[E->V2][E->V1] = E->Weight;
}

MGraph* BuildGraph(int N, int M)
{
    MGraph* MG = CreateMGraph(N);
    if (M == 0)
        return MG;
    else {
        for (int i = 0; i < M; i++) {
            Edge* E = (Edge*)malloc(sizeof(struct ENode));
            scanf("%d %d", &E->V1, &E->V2);
            E->V1--;
            E->V2--;
            E->Weight = 1;
            InsertEdge(MG, E);
        }
    }
    return MG;
}

float BFS(MGraph* MG, int V, int* visited, Queue* Q)
{
    int* q; int qV;
    int count = 1; int level = 0;
    visited[V] = 1;
    Enqueue(Q, V, level++);
    while (Q->front->next != NULL) {
        q = Dequeue(Q);
        qV = q[0];
        if (q[1] == level)
            level++;
        if (level > 6)
            break;
        for (int W = 0; W < MG->Nv; W++) {
            if (MG->G[qV][W] == 1 && visited[W] == 0) {
                count++;
                visited[W] = 1;
                Enqueue(Q, W, level);
            }
        }
    }
    float per = (float)count / MG->Nv;
    return per;
}

void SDS(MGraph* MG)
{
    float percent;
    Queue* Q = initQueue(); int* q;
    int* visited = (int*)malloc(MG->Nv * sizeof(int));
    for (int V = 0; V < MG->Nv; V++) {
        for (int i = 0; i < MG->Nv; i++)
            visited[i] = 0;
        percent = BFS(MG, V, visited, Q);
        printf("%d: %.2f%%\n", V + 1, percent*100);
        while (Q->front != Q->rear)
            q = Dequeue(Q);
    }
}

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf(" %d", &M);
    MGraph* MG = BuildGraph(N, M);
    SDS(MG);

    return 0;
}
