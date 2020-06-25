#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct RNode Node;
struct RNode {
	Node* front;
	int data;
	Node* rear;
};

Node* Read()
{
	int num;
	printf("Input original list number: ");
	scanf("%d", &num);
	Node* head = (Node*)malloc(sizeof(struct RNode));
	head->data = num;
	head->rear = NULL;
	Node* tmp = head;
	for (int i = 0; i < num; i++) {
		Node* p = (Node*)malloc(sizeof(struct RNode));
		scanf("%d", &p->data);
		p->rear = NULL;
		p->front = tmp;
		tmp->rear = p;
		tmp = p;
	}
	return head;
}

void Swap(Node* a, Node* b)
{
	int tmp;
	tmp = b->data;
	b->data = a->data;
	a->data = tmp;
}

void Reverse(Node* list, int N, int K)
{
	int t = N / K;
	Node* start = list->rear;
	Node* last;
	Node* next;
	while (t--) {
		last = start;
		for (int i = 1; i < K; i++)
			last = last->rear;
		next = last->rear;
		do {
			Swap(start, last);
			start = start->rear;
			last = last->front;
		} while (start->front != last && start != last);
		start = next;
	}
}

int main()
{
	Node* list = Read();
	int num = list->data;
	int k;
	printf("Input reverse sublist number: ");
	scanf("%d", &k);
	Reverse(list, num, k);
	for (Node* p = list->rear; p; p = p->rear)
		printf("%d ", p->data);
	printf("\n");

	return 0;
}