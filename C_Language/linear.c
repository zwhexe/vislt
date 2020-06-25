#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct SList{
    int data[MAX];
    int length;
};

void init(struct SList *p){
    p->length = 0;
}

void printList(struct SList* p){
    for(int i = 0; i < p->length; i++)
        printf("%d ",p->data[i]);
    putchar('\n');
}

int insert(struct SList* p, int k, int x){
    if(k<0 || k>p->length || p-length==MAX-1){
        return 0;}
    else{
        for(int i=p->length; i>=k; i--){
            p->data[i+1] = p->data[i];
        }
        p->data[k] = x;
        p->length += 1;
        return 1; 
    }
}

int erase(struct SList* p, int k, int* px){
    if(k<0 || k>=p->length) 
        return 0;
    else{
        *px = p->data[k];
        for(int i = k+1; i<p->length; i++)
            p->data[i-1] = p->data[i];
        p->length--;
        return 1;
    }
}

int main(int argc, const char** argv)
{
    struct SList a;
    init(&a);
    int k = 1;
    int x = 11;
    int y = 22;
    insert(&a, k, x);
    int z;
    erase(&a, k, &z);
    printList(&a);
    return 0;
}