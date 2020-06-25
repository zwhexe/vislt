#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Polynomial {
	int para;
	int exp;
	struct Polynomial *next;
} Node;

Node* Read()
{
	int num;
	scanf_s("%d", &num);
	int* arr_para;
	int* arr_exp;
	arr_para = (int*)malloc(num * (sizeof(int)));
	arr_exp = (int*)malloc(num * (sizeof(int)));
	for (int i = 0; i < num; i++) {
 		scanf_s("%d%d", &arr_para[i], &arr_exp[i]);
	}
	Node* poly = NULL;
	
	if (num > 0) {
		Node* p = (Node*)malloc(sizeof(struct Polynomial));
		p->para = arr_para[0];
		p->exp = arr_exp[0];
		p->next = NULL;
		poly = p;
	}
	else
		return NULL;

	Node* tmp = poly;
	for (int i = 1; i < num; i++) {
		Node* p = (Node*)malloc(sizeof(struct Polynomial));
		p->para = arr_para[i];
		p->exp = arr_exp[i];
		p->next = NULL;
		tmp->next = p;
		tmp = p;
	}
	free(arr_exp);
	free(arr_para);
	return poly;
}

Node* Multi(Node* list1, Node* list2)
{	
	Node* P = (Node*)malloc(sizeof(struct Polynomial));
	P->next = NULL;
	Node* p1 = list1;
	Node* p2 = list2;
	Node* t1 = p1;
	Node* t2 = p2;
	Node* tmp = P;
	
	while (t1) {
		Node* p = (Node*)malloc(sizeof(struct Polynomial));
		p->next = NULL;
		p->exp = t1->exp + t2->exp;
		p->para = t1->para * t2->para;
		t1 = t1->next;
		tmp->next = p;
		tmp = p;
	}

	t2 = p2->next;
	while (t2) {
		t1 = p1;
		while (t1) {
			Node* t = (Node*)malloc(sizeof(struct Polynomial));
			t->next = NULL;
			t->exp = t1->exp + t2->exp;
			t->para = t1->para * t2->para;
			t1 = t1->next;
			Node* cp = P->next;
			BOOL flag = FALSE;
			while (t->exp < cp->exp && flag!= TRUE) {
				if (cp->next != NULL) {
					if (t->exp == cp->next->exp) {
						cp->next->para += t->para;
						flag = TRUE;
						free(t);
					}
					else if (t->exp > cp->next->exp) {
						t->next = cp->next;
						cp->next = t;
						flag = TRUE;
					}
					else
						cp = cp->next;
				}
				else {
					cp->next = t;
					flag = TRUE;
				}
			}
		}
		t2 = t2->next;
	}
	return P;
}

Node* Add(Node* list1, Node* list2)
{
	Node* p1 = list1;
	Node* p2 = list2;
	Node* P = (Node*)malloc(sizeof(struct Polynomial));
	P->next = NULL;
	Node* tmp = P;
	while (p1 && p2) {
		Node* p = (Node*)malloc(sizeof(struct Polynomial));
		p->next = NULL;
		if (p1->exp > p2->exp) {
			p->exp = p1->exp;
			p->para = p1->para;
			p1 = p1->next;
		}
		else if(p1->exp < p2->exp) {
			p->exp = p2->exp;
			p->para = p2->para;
			p2 = p2->next;
		}
		else {
			p->exp = p1->exp;
			p->para = p1->para + p2->para;
			p1 = p1->next;
			p2 = p2->next;
		}
		tmp->next = p;
		tmp = p;
	}
	while (p1) {
		Node* p = (Node*)malloc(sizeof(struct Polynomial));
		p->next = NULL;
		p->exp = p1->exp;
		p->para = p1->para;
		p1 = p1->next;
		tmp->next = p;
		tmp = p;
	}
	while (p2) {
		Node* p = (Node*)malloc(sizeof(struct Polynomial));
		p->next = NULL;
		p->exp = p2->exp;
		p->para = p2->para;
		p2 = p2->next;
		tmp->next = p;
		tmp = p;
	}
	return P;
}


int main()
{
	Node* list1;
	Node* list2;
	list1 = Read();
	list2 = Read();

	Node* multi = Multi(list1, list2);
	for (Node* p = multi->next; p; p = p->next){
		if (p->para != 0)
			printf("%d %d ", p->para, p->exp);
	}
	printf("\n");

	Node* add = Add(list1, list2);
	for (Node* p = add->next; p; p = p->next) {
		if (p->para != 0)
			printf("%d %d ", p->para, p->exp);
	}
	printf("\n");

	return 0;
}