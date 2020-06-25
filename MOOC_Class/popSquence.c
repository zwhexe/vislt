#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Stack Node;
struct Stack {
	int data;
	int capacity;
	Node* next;
};

Node* Read(int N)
{
	Node* top = NULL;
	for (int i = 0; i < N; i++) {
		Node* p = (Node*)malloc(sizeof(struct Stack));
		scanf("%d", &p->data);
		p->capacity = i+1;
		p->next = top;
		top = p;
	}
	return top;
}

BOOL rePush(int M, int N, Node* pop)
{
	BOOL success = TRUE;
	Node* top = NULL;
	int count = 0;
	int require = N;
	while (pop && success==TRUE) {
		if (top != NULL && top->data == require) {
			Node* tmp = top;
			top = top->next;
			free(tmp);
			require--;
		}
		else if (pop->data == require) {
			require--;
			pop = pop->next;
		}
		else if (pop->data != require) {
			Node* m = (Node*)malloc(sizeof(struct Stack));
			m->data = pop->data;
			m->capacity = ++count;
			m->next = top;
			top = m;
			pop = pop->next;
		}	
		if (top != NULL && top->capacity > M) {
			printf("Exceed Capacity!");
			success = FALSE;
		}
	}
	if (success == TRUE && require > 0) {
		for (Node* p = top; p; p = p->next)
			if (p->data != require) {
				printf("Order Incorrect!");
				success = FALSE;
				break;
			}
			else {
				require--;
			}
	}
	return success;
}


int main()
{
	int N;
	printf("Input push numbers N: ");
	scanf("%d", &N);
	Node* pop = Read(N);

	int M;
	printf("Input capacity M: ");
	scanf("%d", &M);
	BOOL success = rePush(M, N, pop);
	if (success == TRUE)
		printf("\nSuccess!\n");
	else
		printf("\nFail!\n");

	return 0;
}