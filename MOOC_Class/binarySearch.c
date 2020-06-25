#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;  // L is a Pointer struct
    ElementType X;
    Position P;
    //L = ReadInput();
    L = (List)malloc(sizeof(struct LNode));

    int list[] = { 12,31,55,89,101,24,67,72 };
    int len = sizeof(list) / sizeof(list[0]);
    for (int i = 0; i < len; i++)
        L->Data[i] = list[i];
    L->Last = len;
    scanf_s("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X)
{
    int left = 0;
    int right = L->Last-1;
    int mid = (left + right) / 2;
    int isFound = 0;
    while (isFound == 0 && (right - left) > 1)
    {
        if (L->Data[mid] == X) {
            isFound = mid + 1;
        }
        else if (L->Data[left] == X) {
            isFound = left + 1;
        }
        else if (L->Data[right] == X) {
            isFound = right + 1;
        }
        else if (L->Data[mid] > X) {
            right = mid;
            mid = (left + right) / 2;
        }
        else if (L->Data[mid] < X) {
            left = mid;
            mid = (left + right) / 2;
        }
    }

    if (isFound == 0) {
            return NotFound;
    }
    else
        return isFound;
}