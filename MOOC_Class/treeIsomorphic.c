#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxTree 10
#define ElemType char
#define Tree int
#define Null -1

struct TreeNode {
	ElemType elem;
	Tree left;
	Tree right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
	int root;
	int N;
	scanf("%d", &N);
	int check[MaxTree] = {0};
	ElemType cl, cr;
	if (N) {
		for (int i = 0; i < N; i++) 
			check[i] = 0;
		for (int i = 0; i < N; i++) {
			printf("Positon %d: ", i);
			scanf("\n%c", &T[i].elem);
			scanf(" %c", &cl);
			scanf(" %c", &cr);
			if (cl != '-') {
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else
				T[i].left = Null;
			if (cl != '-') {
				T[i].right = cl - '0';
				check[T[i].right] = 1;
			}
			else
				T[i].right = Null;
		}
		int i;
		for (i = 0; i < N; i++)
			if (!check[i]) break;
		root = i;
	}
	return root;
}

int isomorphic(Tree R1, Tree R2)
{
	if ((R1 == Null) && (R2 == Null))
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R2 == Null) && (R1 != Null)))
		return 0;
	if (T1[R1].elem != T2[R2].elem)
		return 0;
	if ((T1[R1].left == Null) && (T2[R1].left == Null))
		return isomorphic(T1[R1].right, T2[R2].right);
	if (((T1[R1].left != Null) && (T2[R2].left != Null)) &&
		((T1[T1[R1].left].elem) == (T2[T2[R2].left].elem)))
		return (isomorphic(T1[R1].left, T2[R2].left) &&
			isomorphic(T1[R1].right, T2[R2].right));
	else
		return (isomorphic(T1[R1].left, T2[R2].right) &&
			isomorphic(T1[R1].right, T2[R2].left));
}

int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);

	// R1&R2 are the root num for each tree, if -1 is NULL
	if (isomorphic(R1, R2))
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}