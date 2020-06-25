#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
	int V;
	int tag;
	struct TreeNode* left;
	struct TreeNode* right;
} Node;

typedef struct AnsNode {
	int flag;
	struct AnsNode* next;
} Ans;

Node* InsertTree(Node* T, int v)
{	
	if (!T) {
		Node* t = (Node*)malloc(sizeof(Node));
		t->V = v;
		t->tag = 0;
		t->left = NULL;
		t->right = NULL;
		T = t;
	}
	else if (v < T->V) {
		T->left = InsertTree(T->left, v);
	}
	else if (v > T->V) {
		T->right = InsertTree(T->right, v);
	}
	return T;
}

Node* BuildTree(int N)
{
	Node* T = (Node*)malloc(sizeof(Node));
	T->tag = 0;
	T->left = NULL;
	T->right = NULL;
	scanf("%d", &T->V);
	for (int i = 1; i < N; i++) {
		int v;
		scanf(" %d", &v);
		T = InsertTree(T, v);
	}
	return T;
}

int CheckTree(Node* T, int v)
{
	if (T->tag) {
		if (v < T->V)
			return CheckTree(T->left, v);
		else if (v > T->V)
			return CheckTree(T->right, v);
		else return 0;
	}
	else {
		if (v == T->V) {
			T->tag = 1;
			return 1;
		}
		else
			return 0;
	}
}

void ResetTree(Node* T)
{
	if (T->left)
		ResetTree(T->left);
	if (T->right)
		ResetTree(T->right);
	T->tag = 0;
}

Ans* JudgeTree(Ans* head, int N)
{
	int L;
	scanf(" %d", &L);
	Ans* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}

	Node* T = BuildTree(N);
	while (L--) {
		int n = N;
		int v;
		scanf("%d", &v);
		int t = CheckTree(T, v);
		while (--n) {
			scanf(" %d", &v);
			t = t * CheckTree(T, v);
		}
		Ans* a = (Ans*)malloc(sizeof(struct AnsNode));
		a->flag = t;
		a->next = NULL;
		tmp->next = a;
		tmp = a;
		ResetTree(T);
	}
	return head;
}

int main()
{
	Ans* ans = (Ans*)malloc(sizeof(Ans));
	ans->next = NULL;
	int N;
	scanf("%d", &N);
	while (N != 0) {
		ans = JudgeTree(ans, N);
		scanf("%d", &N);
	}

	for (Ans* tmp = ans->next; tmp; tmp = tmp->next) {
		if (tmp->flag == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}