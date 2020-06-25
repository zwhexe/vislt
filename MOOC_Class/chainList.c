#include <stdio.h>
#include <stdlib.h>

typedef struct LNode* List;
struct LNode{
	int data;
	List* next;
};

int Length(List L)
{
	List p;
	int n;
	while(p){
		p = p->next;
		n++;
	}
	return n;
}

List Find(int Pos, List L)
{
	List p;
	int len = Length(L);
	int i;
	while(p != NULL && i < len)
	{
		p = p->next;
		i++;
	}
	if (i == len)
		return p;
	else
		return NULL;
}

List Insert(int x, int Pos, List L)
{
	List p = (list)malloc(sizeof(struct LNode));
	p->data = x;
	if(Pos == 0){
		p->next = L;
		return p;
	}
	pp = Find(Pos-1, L);
	if(pp == NULL)
		return NULL;
	else{
		p->next = pp->next;
		pp->next = p;
		return L;
	}
}

List Delete(int Pos, List L)
{
	List p, pp;
	if(Pos == 0){
		pp = L;
		if(L!=NULL)
			L = L->next;
		else return NULL;
		free(pp);
		return L;
	}
	pp = Find(Pos-1, L);
	if(pp->next==NULL)
		return NULL;
	else{
		p = pp->next;
		pp->next = p->next;
		free(p);
		return L;
	}
}