#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000

typedef struct ENode Edge;
struct ENode{
    int pos;
    Edge* next;
};

typedef struct LNode List;
struct LNode{
    int key;
    int pos;
    int indegree;
    Edge* next;
};

typedef struct HNode HashTable;
struct HNode{
    int TableSize;
    List* Head;
};

typedef struct HeapNode Heap;
struct HeapNode{
    int* data;
    int size;
    int capacity;
};

int Hash(int Key, int Tsize)
{
    return Key%Tsize;
}

int NextPrime(int N)
{
    int i, p = (N%2)?N:N+1;
    while(p < MAX){
        for(i = (int)sqrt(p); i>2; i--)
            if(!(p%i)) break;
        if(i==2) break;
        else p+=2;
    }
    return p;
}

int Find(HashTable* H, int Key)
{
    int pos;
    // move pointer to right pos as key value
    pos = Hash(Key, H->TableSize);
    for(int i = 0; i < H->TableSize; i++){
        if(H->Head[pos].key == Key)
            break;
        else
            pos++;
        if(pos >= H->TableSize)
            pos = 0;
    }
    return pos;
}

void InsertHeap(Heap* heap, int x)
{
    int i = ++heap->size;
    for(; x < heap->data[i/2]; i/=2)
        heap->data[i] = heap->data[i/2];
    heap->data[i] = x;
}

int DeleteHeap(Heap* heap)
{
    if(heap->size == 0)
        return -1;
    int min = heap->data[1];
    int last = heap->data[heap->size--];
    int parent, child;
    
    for(parent = 1; parent*2 <= heap->size; parent = child){
        child = parent*2;
        if(child!=heap->size && heap->data[child+1] < heap->data[child])
            child++;
        if(last <= heap->data[child]) break;
        else
            heap->data[parent] = heap->data[child];
    }
    heap->data[parent] = last;
    return min;
}

void TopSort(HashTable* H)
{
    Heap* heap = (Heap*)malloc(sizeof(struct HeapNode));
    heap->data = (int *)malloc(H->TableSize*sizeof(int));
    heap->capacity = H->TableSize;
    heap->size = 0;
    heap->data[0] = -MAX;
    for(int i = 0; i < H->TableSize; i++)
        if(H->Head[i].indegree == 0)
            InsertHeap(heap, H->Head[i].key);
    
    int key, pos;
    Edge* tmp;
    while(heap->size != 0){
        key = DeleteHeap(heap);
        pos = Find(H, key);
        H->Head[pos].indegree--;
        tmp = H->Head[pos].next;
        while(tmp != NULL){
            H->Head[tmp->pos].indegree--;
            if(H->Head[tmp->pos].indegree==0)
                InsertHeap(heap, H->Head[tmp->pos].key);
            tmp = tmp->next;
        }
        printf("%d", key);
        if(heap->size != 0) printf(" ");
        else printf("\n");
    }    
}

HashTable* CreateTable(int N)
{
    HashTable* H = (HashTable*)malloc(sizeof(struct HNode));
    H->TableSize = NextPrime(N);
    H->Head = (List*)malloc(H->TableSize*sizeof(struct LNode));
    for(int i = 0; i < H->TableSize; i++){
        H->Head[i].key = -1;
        H->Head[i].pos = -1;
        H->Head[i].indegree = -1;
        H->Head[i].next = NULL;
    }

    int key, pos, indegree;
    for(int i = 0; i < N; i++){
        scanf("%d", &key); getchar();
        if(key < 0) continue;
        pos = Hash(key, H->TableSize);
        H->Head[i].key = key;
        H->Head[i].pos = pos;   // judge relationship between pos and i
        H->Head[i].indegree = (i-pos) >= 0 ? i-pos : H->TableSize + i - pos;

        for(int j = 0; j < H->Head[i].indegree; j++){
            int k = pos+j;
            if(k >= H->TableSize)
                k -= H->TableSize;
            Edge* E = (Edge*)malloc(sizeof(struct ENode));
            E->pos = i;
            E->next = H->Head[k].next;
            H->Head[k].next = E;
        }
    }

    return H;
}



int main()
{
    int N;
    scanf("%d", &N);
    HashTable* H = CreateTable(N);
    
    TopSort(H);

    return 0;
}