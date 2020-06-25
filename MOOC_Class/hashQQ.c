#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct UNode User;
struct UNode{
    long ID;
    char passwd[17];
    User* next;
};

typedef struct HNode HashTable;
struct HNode{
    int TableSize;
    User* Users;
};

int NextPrime(int N)
{
    int i;
    int P = (N%2)?N+2:N+1;  //odd+2:even+1
    while(P <= 100000){
        for(i = (int)sqrt(P); i>2; i--){
            if(!(P%i)) break;
        }
        if (i==2) break;
        else P+= 2; // P is not prime, test next
    }
    return P;
}

int Hash(long key, int max)
{
    return key%max;
}

int Register(HashTable* H, long ID, char* passwd)
{
    int Found = 0;
    int pos = Hash(ID, H->TableSize);
    User* U = H->Users[pos].next;
    while(U != NULL){
        if(U->ID == ID){
            Found = 1;
            break;
        }
        else
            U = U->next;
    }

    if(Found == 1){
        // printf("ERROR: Exist\n");
        return 1;
    }
    else{
        User* N = (User*)malloc(sizeof(struct UNode));
        N->ID = ID;
        strcpy(N->passwd, passwd);
        N->next = H->Users[pos].next;
        H->Users[pos].next = N;
        // printf("New: OK\n");
        return 2;
    }
}

int Login(HashTable* H, long ID, char* passwd)
{
    int Found = 0;
    int pos = Hash(ID, H->TableSize);
    User* U = H->Users[pos].next;
    while(U != NULL){
        if(U->ID = ID){
            Found = 1;
            break;
        }
        else
            U = U->next;
    }
    
    if(Found == 1){
        if(strcmp(U->passwd, passwd) == 0)
            // printf("Login: OK\n");
            return 3;
        else
            // printf("ERROR: Wrong PW\n");
            return 4;
    }
    else
        // printf("ERROR: Not Exist\n");
        return 5;
}

int main()
{
    int N;
    scanf("%d", &N); getchar();
    HashTable* H = (HashTable*)malloc(sizeof(struct HNode));
    H->TableSize = NextPrime(N);
    H->Users = (User*)malloc(H->TableSize*sizeof(struct UNode));
    for(int i = 0; i < H->TableSize; i++){
        H->Users[i].ID = 0;
        H->Users[i].passwd[0] = '\0';
        H->Users[i].next = NULL;
    }

    int* ans = (int*)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++)
        ans[i] = 0;

    char input;
    long ID;
    char passwd[17];
    for(int i = 0; i < N; i++){
        scanf("%c %ld %s", &input, &ID, passwd);
        getchar();
        // there have to check passwd length!
        if(input == 'N')
            ans[i] = Register(H, ID, passwd);
        else if(input == 'L')
            ans[i] = Login(H, ID, passwd);
    }

    for(int i = 0; i < N; i++){
        switch(ans[i]){
            case 1: printf("ERROR: Exist\n"); continue;
            case 2: printf("New: OK\n"); continue;
            case 3: printf("Login: OK\n"); continue;
            case 4: printf("ERROR: Wrong PW\n"); continue;
            case 5: printf("ERROR: Not Exist\n"); continue;
        }
    }

    return 0;
}