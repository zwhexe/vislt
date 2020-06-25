#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int data;
    int parent;
} Node;

int Find(Node* S, int X, int N)
{
    int i;
    for (i = 0; i < N && S[i].data != X; i++);
    if (i >= N) return -1;
    for (; S[i].parent >= 0; i = S[i].parent);
    return i;
}

void Union(Node* S, int x, int y, int N)
{
    int root1, root2;
    root1 = Find(S, x, N);
    root2 = Find(S, y, N);
    if (S[root1].parent > S[root2].parent) {  // root2 has more nodes than root1
        S[root2].parent += S[root1].parent;
        S[root1].parent = root2;
    }
    else {  // root1 is not less than root2
        S[root1].parent += S[root2].parent;
        S[root2].parent = root1;
    }
}

void Input(Node* S, int N)
{
    int x, y;
    scanf(" %d", &x);
    scanf(" %d", &y);
    Union(S, x, y, N);
}

int Check(Node* S, int N)
{
    int x, y;
    scanf(" %d", &x);
    scanf(" %d", &y);
    int root1, root2;
    root1 = Find(S, x, N);
    root2 = Find(S, y, N);
    if (root1 == root2)
        return 1;
    else
        return -1;
}

int Count(Node* S, int N)
{
    int m = 0;
    for (int i = 0; i < N; i++)
        if (S[i].parent < 0)
            m += 1;
    return m;
}

int main()
{
    int N;
    char ch;
    scanf("%d", &N);
    Node* S = (Node*)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        (S + i)->data = i + 1;
        (S + i)->parent = -1;
    }

    int i = 0;
    int arr[MAX] = { 0 };
    do {
        scanf("%c", &ch);
        switch (ch) {
        case 'I': Input(S, N); break;
        case 'C': arr[i++] = Check(S, N); break;
        case 'S': arr[i++] = Count(S, N); break;
        }
    } while (ch != 'S');

    for (int j = 0; j < i - 1; j++)
        if (arr[j] == 1)
            printf("yes\n");
        else if (arr[j] == -1)
            printf("no\n");
    if (arr[i - 1] == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", arr[i - 1]);

    return 0;
}