#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// typedef struct _node {
// 	int value;
// 	struct _node *next;
// } Node;

typedef struct _list {
	Node *head;
	Node *tail;
} List;

void node_add(int num, List *list);
void node_print(const List *list);
void node_find(const int num, const List *list);
void node_delete(const int num, List *list);
void node_erase(List *list);

int main(int argc, char const *argv[])
{
	int num[] = {1,2,3,4,5};
	int len = sizeof(num)/sizeof(num[0]);
	
	List list;
	list.head = NULL;
	list.tail = NULL;

	for(int i=0; i < len; i++)
		node_add(num[i], &list);

	node_print(&list);

	int a = 6;
	node_find(a, &list);

	int b = 3;
	node_delete(b, &list);
	node_print(&list);

	node_erase(&list);
	//node_print(&list);
	if(list.head == NULL)
		printf("list is NULL\n");
	else
		printf("%d\n", list.head->value);

	return 0;
}

void node_print(const List *list)
{
	Node *p = NULL;
	if(list->head == NULL){
		printf("This list is empty!");
	}
	else{
		for(p = list->head; p; p=p->next)
			printf("%d\t", p->value);
	}
	printf("\n");
}

void node_add(int num, List *list)
{
	// create node to store number
	Node *pnode = (Node *)malloc(sizeof(Node));
	pnode->value = num;
	pnode->next = NULL;
	// find the last node of original list
	if(list->head){
		(list->tail)->next = pnode;
		list->tail = pnode;
	}
	else{
		list->head = pnode;
		list->tail = pnode;
	}
}

void node_find(const int a, const List *list)
{
	int isFound = 0;
	Node *p = NULL;
	for(p = list->head; p; p=p->next)
	{
		if(p->value == a){
			isFound = 1;
			break;
		}
	}
	if(isFound != 0)
		printf("We found %d in the list\n", a);
	else
		printf("The list don't have %d\n", a);
}

void node_delete(const int a, List *list)
{	
	Node *p = list->head;
	Node *q = NULL;
	for(; p;q=p, p=p->next)
	{
		if(p->value == a){
			if(q){
				q->next = p->next;

			}
			else{
				list->head = p->next;
			}
			free(p);
			break;
		}
	}
}

void node_erase(List *list)
{
	Node *p = NULL;
	Node *q = NULL;
	for(p = list->head; p; p=q){
		q = p->next;
		free(p);
	}
	list->head = NULL;
}