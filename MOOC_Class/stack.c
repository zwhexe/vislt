#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int ElemType;
typedef struct SNode *Stack;
struct SNode{
	ElemType data;
	Stack next;  // a pointer as top of stack
};

Stack initStack()
{	// Head of the Stack also Top, so it's just pointer without data
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->next = NULL;
	return S;
}

int isEmpty(Stack S)
{
	return (S->next == NULL);
}

void Push(ElemType item, Stack S)
{
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->data = item;
	tmp->next = S->next;
	S->next = tmp;
}

ElemType Pop(Stack S)
{
	if(S->next == NULL)
		return NULL;
	else{
		Stack top;
		top = S->next;
		S->next = top->next;
		topElem = top->data;
		free(top);
		return topElem;
	}
}