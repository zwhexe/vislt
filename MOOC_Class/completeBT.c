#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} Node;

void InsertTree(Node* tmp, Node* t)
{
	if (t->data < tmp->data) {
		if (tmp->left)
			InsertTree(tmp->left, t);
		else
			tmp->left = t;
	}
	else {
		if (tmp->right)
			InsertTree(tmp->right, t);
		else
			tmp->right = t;
	}
}

void BuildTree(Node* root, int N)
{
	Node* tmp = root;
	while (--N) {
		Node* t = (Node*)malloc(sizeof(Node));
		scanf(" %d", &t->data);
		t->left = NULL;
		t->right = NULL;
		InsertTree(tmp, t);
	}
}

void InorderPop(Node* root, int* arr)
{
	static int i = 0;
	if (root) {
		InorderPop(root->left, arr);
		*(arr + (i++)) = root->data;
		InorderPop(root->right, arr);
	}
}

void InorderTo(Node* err, int* arr)
{
	static int j = 0;
	if (err) {
		InorderTo(err->left, arr);
		err->data = *(arr + (j++));
		InorderTo(err->right, arr);
	}
}


int main()
{
	int N;
	scanf("%d", &N);
	Node* root = (Node*)malloc(sizeof(Node));
	scanf("%d", &root->data);
	root->left = NULL;
	root->right = NULL;
	BuildTree(root, N);

	int* arr = (int *)malloc(N * sizeof(int));
	InorderPop(root, arr);

	Node* err = (Node*)malloc(N * sizeof(Node));
	for (int i = 0, j = 0; i < N; i++) {
		j = 2 * i + 1;
		(err + i)->data = 0;
		if (j < N)
			(err + i)->left = err + j;
		else
			(err + i)->left = NULL;
		j = i * 2 + 2;
		if (j < N)
			(err + i)->right = err + j;
		else
			(err + i)->right = NULL;
	}

	InorderTo(err, arr);
	for(int i = 0; i < N; i++)
		printf("%d ", (err+i)->data);

	return 0;
}