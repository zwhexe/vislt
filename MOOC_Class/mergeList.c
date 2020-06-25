#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mooc.h"

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();    /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */
List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();

    printf("\n");
    Print(L1);
    Print(L2);
    printf("\n");

    L = Merge(L1, L2);
    Print(L);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read()
{
    List L = NULL;
    int num;
    scanf_s("%d\n", &num);

    if (num == 0)
        return NULL;

    for (int i = 0; i < num; i++) {
        PtrToNode p;
        p = (PtrToNode)malloc(sizeof(struct Node));
        scanf_s("%d", &p->Data);
        p->Next = NULL;
        if (L == NULL) {
            L = p;
        }
        else {
            PtrToNode tmp = L;
            while (tmp->Next)
                tmp = tmp->Next;
            tmp->Next = p;
        }
    }
    return L;
}

void Print(List L)
{
    if (L == NULL)
        return;
    PtrToNode p = L;
    while (p) {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

List Merge(List L1, List L2)
{
    if (L1 == NULL && L2 == NULL)
        return NULL;

    List L = NULL;
    PtrToNode tmp = L;
    PtrToNode p1 = L1;
    PtrToNode p2 = L2;

    while (p1 != NULL || p2 != NULL) {
        PtrToNode p;
        p = (PtrToNode)malloc(sizeof(struct Node));
        if (L == NULL) {
            L = p;
            tmp = p;
        }
        else {
            tmp->Next = p;
            //tmp = p;
        }
        if (p1 == NULL && p2 != NULL) {
            p->Data = p2->Data;
            p2 = p2->Next;
            tmp = p;
        }
        else if (p1 != NULL && p2 == NULL) {
            p->Data = p1->Data;
            p1 = p1->Next;
            tmp = p;
        }
        else if (p1->Data < p2->Data) {
            p->Data = p1->Data;
            p1 = p1->Next;
            tmp = p;
        }
        else if (p1->Data > p2->Data) {
            p->Data = p2->Data;
            p2 = p2->Next;
            tmp = p;
        }
        else if (p1->Data == p2->Data) {
            p->Data = p1->Data;
            tmp = p;
            PtrToNode pp = (PtrToNode)malloc(sizeof(struct Node));
            tmp->Next = pp;
            pp->Data = p2->Data;
            tmp = pp;
            p1 = p1->Next;
            p2 = p2->Next;
        }
    }
    tmp->Next = NULL;
    return L;
}