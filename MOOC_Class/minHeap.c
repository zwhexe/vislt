#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 1000
#define MAXDATA 10000

typedef struct HeapStruct {
	int* data;
	int size;
	int capacity;
} Heap;

Heap* minHeap(int N)
{
	Heap* H = (Heap*)malloc(sizeof(Heap));
	H->data = (int*)malloc(N * sizeof(int));
	H->size = 0;
	H->capacity = N;
	H->data[0] = -MAXDATA;
	return H;
}

void Insert(Heap* H, int X)
{
	int i = ++H->size;
	for (; H->data[i / 2] > X; i /= 2) {
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = X;
}

void Path(Heap* H, int pos)
{
	for (; pos > 1; pos /= 2)
		printf("%d ", H->data[pos]);
	printf("%d\n", H->data[pos]);
}

int main()
{
	int N, M, X;
	scanf("%d", &N);
	scanf(" %d", &M);
	Heap* H = minHeap(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X);
		Insert(H, X);
	}
	//for (int i = 1; i < N + 1; i++) {
	//	printf("%d\n", H->data[i]);
	//}
	int pos;
	for (int i = 0; i < M; i++) {
		scanf("%d", &pos);
		Path(H, pos);
	}

	return 0;
}