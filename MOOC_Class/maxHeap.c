#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 1000
#define true 1
#define false 0

typedef int ElemType;
typedef int bool;
typedef struct HNode *Heap;
struct HNode {
	ElemType *Data;
	int Size;
	int Capacity;
};

// MaxHeap & MinHeap is same struct
typedef Heap MaxHeap;
typedef Heap MinHeap;

MaxHeap CreateHeap(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElemType *)malloc((MaxSize+1)*sizeof(ElemType));
	H->Size = 0;
	H->Capacity = MaxSize;
	/*
		CreateHeap do not define it is Max or Min
		We will use BuildMaxHeap to restruct it
		But Data[0] gives a hint for coder
	 */
	H->Data[0] = MAXDATA;

	return H;
}

bool Insert(MaxHeap H, ElemType X)
{
	int i;

	if(isFull(H)){
		printf("The Heap is full!");
		return false;
	}
	i = ++H->Size;
	for(; H->Data[i/2] < X; i/=2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;
	return true;
}

#define ERROR -1

bool isEmpty(MaxHeap H)
{
	return (H->Size == 0);
}

ElemType DeleteMax(MaxHeap H)
{
	int Parent, Child;
	ElemType maxItem, X;
	if(isEmpty(H)){
		printf("the Heap is empty!");
		return ERROR;
	}

	maxItem = H->Data[1]; /*to store max*/
	X = H->Data[H->Size--];
	for(Parent = 1; Parent*2<=H->Size; Parent=Child){
		Child = Parent*2;
		if((Child!=H->Size)&&(H->Data[Child]<H->Data[Child+1]))
			Child++;
		if(X >= H->Data[Child]) break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
	return maxItem;
}

/*------Build MaxHeap------*/
void PercDown(MaxHeap H, int p)
{
	int Parent, Child;
	ElemType X;
	X = H->Data[p];
	for(Parent=p; Parent*2<H->Size; Parent=Child){
		Child = Parent*2;
		if((Child!=H->Size)&&(H->Data[Child]<H->Data[Child+1]))
			Child++;
		if(X>=H->Data[Child]) break;
		else 
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}

void BuildMaxHeap(MaxHeap H)
{
	int i;
	for (i = H->Size/2; i>0; i--)
		PercDown(H, i);
}