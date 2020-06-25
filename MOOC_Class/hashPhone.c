#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"
#define MAX 100000
#define KEYLEN 11

typedef struct LNode List;
struct LNode{
    int count;
    char data[KEYLEN+1];
    List* next;
};

typedef struct HNode HashTable;
struct HNode{       //hashtable define
    int TableSize;  //hashtable length
    List *Lists;    //point to list array
};

int NextPrime(int N)
{
    int i, p = (N%2)?N+2:N+1;   //start with next odd
    while(p <= 1000000){
        for(i=(int)sqrt(p); i>2; i--){
            if(!(p%i)) break;
        }
        if (i==2) break;
        else  p+=2;
    }
    return p;
}

HashTable* CreateTable(int TableSize)
{
    HashTable* H = (HashTable*)malloc(sizeof(struct HNode));
    H->TableSize = NextPrime(TableSize);
    H->Lists = (List*)malloc(H->TableSize*sizeof(struct LNode));
    for(int i = 0; i < H->TableSize; i++){
        H->Lists[i].data[0] = '\0';
        H->Lists[i].next = NULL;
        H->Lists[i].count = 0;
    }
    return H;
}

void OutputMax(HashTable *H)
{
    char MinPhone[KEYLEN+1];
    int i, MaxCnt = 0, PCnt = 0;
    List* Ptr;
    MinPhone[0] = '\0';
    for(int i=0; i < H->TableSize; i++){
        Ptr = H->Lists[i].next;
        while(Ptr!=NULL){
            if(Ptr->count > MaxCnt){
                MaxCnt = Ptr->count;
                strcpy(MinPhone, Ptr->data);
                PCnt = 1;
            }
            else if(Ptr->count == MaxCnt){
                PCnt++;
                if(strcmp(MinPhone, Ptr->data) > 0)
                    strcpy(MinPhone, Ptr->data);
            }
            Ptr = Ptr->next;
        }
    }
    printf("%s %d", MinPhone, MaxCnt);
    if(PCnt > 1) 
        printf(" %d", PCnt);
    printf("\n");
}

int Hash(int Key, int P)
{
    return Key%P;
}

List* Find(HashTable* H, char* Key)
{
    int pos;
    // move pointer to right pos as key value
    pos = Hash(atoi(Key+KEYLEN-5), H->TableSize);
    List* P;
    P = H->Lists[pos].next;
    while(P && strcmp(P->data, Key))
        P = P->next;
    return P;
}

void Insert(HashTable* H, char* Key)
{
    List* P=NULL;
    int pos;
    P = Find(H, Key);
    if(P==NULL){
        List* NewCell = (List*)malloc(sizeof(struct LNode));
        strcpy(NewCell->data, Key);
        NewCell->count = 1;
        pos = Hash(atoi(Key+KEYLEN-5), H->TableSize);

        NewCell->next = H->Lists[pos].next;
        H->Lists[pos].next = NewCell;
    }
    else{
        P->count++;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    
    HashTable *H = CreateTable(N*2);
    char Key[KEYLEN+1];
    for(int i = 0; i < N; i++){
        scanf("%s", Key); Insert(H, Key);
        scanf("%s", Key); Insert(H, Key);
    }
    OutputMax(H);

    return 0;
} 