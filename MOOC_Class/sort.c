#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void Swap(long* a, long* b)
{
    long tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Bubble_sort(long A[], int N)
{
    int flag;
    long tmp;
    for(int P = N-1; P > 0; P--){
        flag = 0;
        for(int i = 0; i < P; i++){
            if(A[i] > A[i+1]){
                tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

void Insert_sort(long A[], int N)
{   
    int P, i;
    for(P = 1; P < N; P++){
        long tmp = A[P];
        for(i = P; i > 0 && A[i-1] > tmp; i--){
            A[i] = A[i-1];
        }
        A[i] = tmp;
    }
}

void Shell_sort(long A[], int N)
{
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
    int si, i, D, P;
    long tmp;
    for(si = 0; Sedgewick[si] >= N; si++)
        ;
    for(D = Sedgewick[si]; D>0; D = Sedgewick[++si])
        for(P = D; P < N; P++){
            tmp = A[P];
            for(i = P; i>=D && A[i-D]>tmp; i-=D)
                A[i] = A[i-D];
            A[i] = tmp;
        }
}

void Merge(long* A, long* tmpA, int L, int REnd, int R)
{
    int LEnd = R - 1;
    int tmp = L;
    int N = REnd - L + 1;
    while(L<=LEnd && R<=REnd){
        if(A[L] <= A[R])
            tmpA[tmp++] = A[L++];
        else 
            tmpA[tmp++] = A[R++];
    }
    while(L <= LEnd)
        tmpA[tmp++] = A[L++];
    while(R <= REnd)
        tmpA[tmp++] = A[R++];
    // At this place, L & R cannot be used
    for(int i = 0; i < N; i++, REnd--)
        A[REnd] = tmpA[REnd];
}

void MSort(long* A, long* tmpA, int L, int REnd)
{
    int Center;
    if(L<REnd){
        Center = (L + REnd)/2;
        MSort(A, tmpA, L, Center);
        MSort(A, tmpA, Center+1, REnd);
        Merge(A, tmpA, L, REnd, Center+1);
    }
}

void Merge_sort(long A[], int N)
{
    long *tmpA = (long *)malloc(N*sizeof(long));
    if(tmpA != NULL){
        MSort(A, tmpA, 0, N-1);
        free(tmpA);
    }
    else
        printf("Space is not enough!");
}

long Median3(long A[], int left, int right)
{
    int center = (left + right)/2;
    if(A[left] > A[center])
        Swap(&A[left], &A[center]);
    if(A[left] > A[right])
        Swap(&A[left], &A[right]);
    if(A[center] > A[right])
        Swap(&A[center], &A[right]);
    Swap(&A[center], &A[right-1]);
    return A[right - 1];
}

void QSort(long A[], int left, int right)
{
    int i, j;
    if(left < right){
        long pivot = Median3(A, left, right);
        // A[left] & A[right] are placed alright
        i = left; j = right - 1;
        while(i < j){
            while(A[++i] < pivot) {}
            while(A[j--] > pivot) {}
            if(i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }// place pivot at i where should be
        Swap(&A[i], &A[right - 1]);

        QSort(A, left, i - 1);
        QSort(A, i+1, right);
    }
}

void Quick_sort(long A[], int N)
{
    QSort(A, 0, N-1);
}