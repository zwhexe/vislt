#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct AvlNode {
	int data;
	int depth;
	struct AvlNode* father;
	struct AvlNode* left;
	struct AvlNode* right;
} Node;

Node* BuildTree(Node* root, Node* t, Node* bk)
{
	if (t->data < root->data) {
		root->depth -= 1;
		if (root->depth <= -2)
			bk = root;
		if (root->left) {
			root = root->left;
			BuildTree(root, t, bk);
		}
		else {
			root->left = t;
			t->father = root;
			return bk;
		}
	}
	else if (t->data > root->data){
		root->depth += 1;
		if (root->depth >= 2)
			bk = root;
		if (root->right) {
			root = root->right;
			BuildTree(root, t, bk);
		}
		else {
			root->right = t;
			t->father = root;
			return bk;
		}
	}
}

void LLTree(Node* bk, Node* ck, Node* dk, Node* head)
{
	if (bk->father)
	{
		Node* ak;
		ak = bk->father;
		if (ak->left == bk)
			ak->left = ck;
		else
			ak->right = ck;
		ck->father = ak;
	}
	else {
		head->father = ck;
		ck->father = NULL;
	}

	if (ck->right) {
		bk->left = ck->right;
		bk->left->father = ck;
	}
	else {
		bk->left = NULL;
	}
	ck->right = bk;
	bk->father = ck;
}

void RRTree(Node* bk, Node* ck, Node* dk, Node* head)
{
	if (bk->father)
	{
		Node* ak;
		ak = bk->father;
		if (ak->left == bk)
			ak->left = ck;
		else
			ak->right = ck;
		ck->father = ak;
	}
	else {
		head->father = ck;
		ck->father = NULL;
	}

	if (ck->left) {
		bk->right = ck->left;
		bk->right->father = ck;
	}
	else {
		bk->right = NULL;
	}
	ck->left = bk;
	bk->father = ck;
}

void LRTree(Node* bk, Node* ck, Node* dk, Node* head)
{
	if (bk->father)
	{
		Node* ak;
		ak = bk->father;
		if (ak->left == bk)
			ak->left = dk;
		else
			ak->right = dk;
		dk->father = ak;
	}
	else {
		head->father = dk;
		dk->father = NULL;
	}

	ck->right = dk->left;
	dk->left = ck; ck->father = dk;
	bk->left = dk->right;
	dk->right = bk; bk->father = dk;
}

void RLTree(Node* bk, Node* ck, Node* dk, Node* head)
{
	if (bk->father)
	{
		Node* ak;
		ak = bk->father;
		if (ak->left == bk)
			ak->left = dk;
		else
			ak->right = dk;
		dk->father = ak;
	}
	else {
		head->father = dk;
		dk->father = NULL;
	}

	ck->left = dk->right;
	dk->right = ck; ck->father = dk;
	bk->right = dk->left;
	dk->left = bk; bk->father = dk;
}

void AvlTree(Node* bk, Node* head)
{
	Node* ck;
	Node* dk;
	if (bk->father) {
		Node* ak;
		ak = bk->father;
	}
	if (bk->depth <= -2) {
		ck = bk->left;
		if (ck->depth <= -1) {
			dk = ck->left;
			LLTree(bk, ck, dk, head);
		}
		else {
			dk = ck->right;
			LRTree(bk, ck, dk, head);
		}
	}
	else {
		ck = bk->right;
		if (ck->depth <= -1) {
			dk = ck->left;
			RLTree(bk, ck, dk, head);
		}
		else {
			dk = ck->right;
			RRTree(bk, ck, dk, head);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	Node* root = (Node*)malloc(sizeof(struct AvlNode));
	scanf("%d", &root->data);
	root->depth = 0;
	root->father = NULL;
	root->left = NULL;
	root->right = NULL;

	Node* head = (Node*)malloc(sizeof(struct AvlNode));
	head->father = root;
	Node* bk;
	bk = root;
	while (--N) {
		Node* t = (Node*)malloc(sizeof(Node));
		scanf(" %d", &t->data);
		t->depth = 0;
		t->father = NULL;
		t->left = NULL;
		t->right = NULL;
		bk = BuildTree(head->father, t, bk);
		if (abs(bk->depth) >= 2)
			AvlTree(bk, head);
	}
	printf("%d\n", head->father->data);
	return 0;
}