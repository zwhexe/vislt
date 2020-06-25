#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct CNode Cell;
struct CNode{
    int data;
    int info;
};

typedef struct HNode HashTable;
struct HNode{
    int TableSize;
    Cell* Cells;
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

int Hash(int Key, int TSize)
{
    return Key%TSize;
}

int Insert(HashTable* H, int Key)
{
    int Pos;
    int flag = 1;
    Pos = Hash(Key, H->TableSize);
    while(flag > 0 && Pos < H->TableSize){
        if(H->Cells[Pos].info == 0){
            H->Cells[Pos].info = 1;
            flag = 0;
        }
        else
            Pos += pow(flag++,2);
    }
    if(flag == 0)
        return Pos;
    else
        return -1;
}

HashTable* CreateTable(int M)
{
    HashTable* H = (HashTable*)malloc(sizeof(struct HNode));
    H->TableSize = NextPrime(M);
    H->Cells = (Cell*)malloc(H->TableSize*sizeof(struct CNode));
    for(int i = 0; i < H->TableSize; i++){
        H->Cells[i].data = 0;
        H->Cells[i].info = 0;
    }
    return H;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    HashTable* H = CreateTable(M);
    int Key, Pos;
    int *arr = (int*)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d", &Key);
        Pos = Insert(H, Key);
        arr[i] = Pos;
    }

    for(int i = 0; i < N; i++){
        if(arr[i] >= 0)
            printf("%d", arr[i]);
        else
            printf("-");

        if(i < N-1)
            printf(" ");
    }
    return 0;
}