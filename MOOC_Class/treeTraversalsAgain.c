#include <stdio.h>
#include <stdlib.h>
#define MaxSize 30

typedef struct TreeNode {
	int data;
	struct Tree* left;
	struct Tree* right;
} Node;

typedef struct TreeStack {
	Node* node;
	struct TreeStack* next;
} Stack;

void AddStack(Stack** T, Node* p)
{
	Stack* tmp = (Stack *)malloc(sizeof(struct TreeStack));
	tmp->node = p;
	tmp->next = *T;
	*T = tmp;
}

Node* PopStack(Stack** T)
{
	if (*T) {
		Stack* tmp = *T;
		Node* t = tmp->node;
		*T = (*T)->next;
		free(tmp);
		return t;
	}
	else
		return NULL;
}

Node* BuildTree(Stack* T, int N)
{
	Node* root = NULL;
	char arr[] = "iiiooiooiioo";
	int num = 1;
	Node* tl = NULL;
	Node* tr = NULL;
	for (int i = 0; i < 2 * N; i++) {
		//scanf_s("\n%c", &action);
		char action = arr[i];
		if (action == 'i') {
			Node* p = (Node*)malloc(sizeof(struct TreeNode));
			p->data = num++;
			printf("Push %d\n", p->data);
			p->left = NULL;
			p->right = NULL;
			if (i > 0) {
				if (arr[i - 1] == 'i') {
					tl = T->node;
					if (tl)
						tl->left = p;
				}
				else if (arr[i - 1] == 'o') {
					tr->right = p;
				}
			}
			AddStack(&T, p);
		}
		else if (action == 'o') {
			tr = PopStack(&T);
			printf("Pop  %d\n", tr->data);
			if (!T->next && i != 2 * N - 1)
				root = tr;
		}		
	}
	return root;
}

void PostorderTraverse(Node* p)
{
	if (p)
	{
		PostorderTraverse(p->left);
		PostorderTraverse(p->right);
		printf("%d ", p->data);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	Stack* T = (Stack*)malloc(sizeof(struct TreeStack));
	T->node = NULL;
	T->next = NULL;
	Node* root = BuildTree(T, N);
	printf("The root is node %d\n", root->data);
	//for (; root; root = root->left)
	//	printf("%d ", root->data);
	PostorderTraverse(root);
	printf("\n");

	return 0;
}