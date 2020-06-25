#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct AdjNode Adj;
struct AdjNode {
	int AdjV;
	// int Weight;
	Adj* next;
};

typedef struct VNode {
	/* FirstNode always represent first linknode */
	int V;
	Adj* FirstNode;
	// char data;
}AdjList[MAX];

typedef struct LNode LGraph;
struct LNode {
	int Nv;
	int Ne;
	AdjList G; //G store FirstNode linking next VNode
};

typedef struct Node QNode;
struct Node{
	int V;
	QNode* next;
};

typedef struct QList Queue;
struct QList {
	QNode* front;
	QNode* rear;
	int length;
};

void InsertEdge(LGraph* Gp)
{
	int V, W;
	scanf("%d", &V);
	scanf(" %d", &W);
	Adj* Adj1 = (Adj*)malloc(sizeof(struct AdjNode));
	Adj1->AdjV = W;
	Adj1->next = Gp->G[V].FirstNode;
	Gp->G[V].FirstNode = Adj1;

	Adj* Adj2 = (Adj*)malloc(sizeof(struct AdjNode));
	Adj2->AdjV = V;
	Adj2->next = Gp->G[W].FirstNode;
	Gp->G[W].FirstNode = Adj2;
}

LGraph* CreateGraph(int N)
{
	LGraph* Gp;
	Gp = (LGraph*)malloc(sizeof(struct LNode));
	Gp->Nv = N;
	Gp->Ne = 0;
	for (int V = 0; V < N; V++) {
		/* Each VNode has no Edge */
		Gp->G[V].V = V;
		Gp->G[V].FirstNode = NULL;
	}
	return Gp;
}

void SortGraph(LGraph* Gp, int N)
{
	int tmp;
	for (int i = 0; i < N; i++) {
		Adj* Vp = Gp->G[i].FirstNode;
		while (Vp != NULL) {
			Adj* Vpp = Vp;
			while (Vpp->next != NULL) {
				if (Vpp->AdjV > Vpp->next->AdjV) {
					tmp = Vpp->AdjV;
					Vpp->AdjV = Vpp->next->AdjV;
					Vpp->next->AdjV = tmp;
				}
				Vpp = Vpp->next;
			}
			Vp = Vp->next;
		}
	}
}

LGraph* BuildGraph(int N, int E)
{
	LGraph* Gp = CreateGraph(N);
	Gp->Ne = E;
	for (int i = 0; i < Gp->Ne; i++) {
		InsertEdge(Gp);
	}
	return Gp;
}

void DFS(LGraph* Gp, int* visited, int i)
{
	printf("%d ", i);
	visited[i] = 1;
	Adj* G = Gp->G[i].FirstNode;
	while(G!=NULL) {
		if (visited[G->AdjV] == 0)
			DFS(Gp, visited, G->AdjV);
		G = G->next;
	}
}

Queue* initQueue()
{
	Queue* Q = (Queue*)malloc(sizeof(struct QList));
	Q->front = Q->rear = (QNode *)malloc(sizeof(struct Node));
	Q->front->V = -1;
	Q->front->next = NULL;
	Q->length = 0;
	return Q;
}

void Enqueue(Queue* Q, QNode* Vp)
{
	Q->rear->next = Vp;
	Q->rear = Vp;
	Q->length += 1;
}

int Dequeue(Queue* Q)
{
	int v = Q->front->next->V;
	QNode* q = Q->front->next;
	if (q == Q->rear) {
		Q->rear = Q->front;
		Q->front->next = NULL;
		Q->length -= 1;
		free(q);
	}
	else {
		Q->front->next = q->next;
		Q->length -= 1;
		free(q);
	}

	return v;
}

void BFS(LGraph* Gp, int* visited, Queue* Q)
{	
	while (Q->length != 0) {
		int v = Dequeue(Q);
		printf("%d ", v);
		Adj* G = Gp->G[v].FirstNode;
		while (G != NULL) {
			if (visited[G->AdjV] == 0) {
				visited[G->AdjV] = 1;
				QNode* Vp = (QNode*)malloc(sizeof(QNode));
				Vp->V = G->AdjV;
				Vp->next = NULL;
				Enqueue(Q, Vp);
			}
			G = G->next;
		}
	}
}

int main()
{
	int N, E;
	scanf("%d", &N);
	scanf(" %d", &E);
	LGraph* Gp;
	Gp = BuildGraph(N, E);
	SortGraph(Gp, N);

	int* visited = (int*)malloc(Gp->Nv * sizeof(int));
	/* Depth-First-Search */
	for (int v = 0; v < Gp->Nv; v++)
		visited[v] = 0;
	
	for (int i = 0; i < Gp->Nv; i++) {
		if (visited[i] == 0) {
			printf("{ ");
			DFS(Gp, visited, i);
			printf("}\n");
		}
	}

	/* Breadth-First-Search */
	for (int v = 0; v < Gp->Nv; v++)
		visited[v] = 0;
	Queue* Q = initQueue(); 
	for (int i = 0; i < Gp->Nv; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			QNode* Vp = (QNode*)malloc(sizeof(struct Node));
			Vp->V = i;
			Vp->next = NULL;
			Enqueue(Q, Vp);
			printf("{ ");
			BFS(Gp, visited, Q);
			printf("}\n");
		}
	}

	return 0;
}