#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int* data;
	int capacity;
	int top;
};

void init(struct Stack* ps, int capacity)
{
	ps->capacity = capacity;
	ps->data = (int *)malloc(sizeof(int)*capacity);
	ps->top = 0;
}

int isFull(const struct Stack *ps)
{
	return ps->top == ps->capacity;
}

int isEmpty(const struct Stack *ps)
{
	return ps->top == 0;
}

int push(struct Stack* ps, int x)
{
	if(isFull(ps))
		return 0;
	else
	{
		ps->data[ps->top++] = x;
		return 1;
	}
}

int pop(struct Stack* ps, int *px)
{
	if(isEmpty(ps)) 
		return 0;
	else
	{
		*px = ps->data[--(ps->top)];
		return 1;
	}
}

int top(const struct Stack* ps, int* px)
{
	if(isEmpty(ps))
		return 0;
	else
	{
		*px = ps->data[ps->top-1];
		return 1;
	}
}

void destroy(struct Stack *ps)
{
	free(ps->data);
}

int main(int argc, const char argv)
{
	struct Stack st;
	init(&st, 5);
	push(&st, 11);
	push(&st, 22);
	push(&st, 33);
	int x;
	pop(&st, &x);
	printf("%d\n", x);
	top(&st, &x);
	printf("%d\n", x);
	destroy(&st);

	return 0;
}