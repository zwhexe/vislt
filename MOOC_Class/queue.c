#include <stdio.h>
#include <stdlib.h>

typedef struct QNode Node
struct Node
{
	int data;
	Node* next;
};

typedef struct QList Queue
struct QList{
	Node* front; // pop
	Node* rear;	// push
	int length;
};

void CreateQueue(Queue *Q)
{
	Q->front = (Node *)malloc(sizeof(struct QNode));
	Q->rear = (Node *)malloc(sizeof(struct QNode));
	Q->length = 0;
	Q->front->next = NULL;
}