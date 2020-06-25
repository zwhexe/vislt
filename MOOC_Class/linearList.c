#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct LinearList *List;
struct LinearList{
	int data[MAXSIZE];
	int last;
};

List initList(){
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LinearList));
	PtrL -> last = -1;
	return PtrL;
}

int Find(int X, List L)
{	
	int i = 0;
	while(L->data[i] != X && i<=L->last){
		i++;
	}
	if(i>L->last) return -1;
	else return i;
}

void Insert(int X, int Pos, List L)
{	
	if(L->last == MAXSIZE-1)
		return;
	int i;
	for(i = L->last; i >= Pos; i--)
		L->data[i+1] = L->data[i];
	L->data[Pos] = X;
	L->last++;
}

void Delete(int Pos, List L)
{
	int i;
	for(int i=Pos; i<L->last; i++)
		L->data[i] = L->data[i+1];
	L->last--;
}

int main()
{
	List pl = initList();
	Insert(100, 9, pl);
	for(int i=0; i<MAXSIZE; i++){
		printf("%d\n",pl->data[i]);
	}
	return 0;
}