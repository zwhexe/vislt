#include <stdio.h>
#include <stdlib.h>

double findKth(int a[], int m, int b[], int n, int k)
{
    if(m>n) // be sure m < n in each recursion
        return findKth(b, n, a, m, k);
    else if(m == 0)
        return b[k-1];
    else if(k==1)
        return a[0]>b[0]?b[0]:a[0];
    
    int pa = k/2>m?m:k/2, pb = k-pa;
    if (a[pa-1] < b[pb-1])
        return findKth(a+pa, m-pa, b, n, k-pa);
    else if(a[pa-1] > b[pb-1])
        return findKth(a, m, b+pb, n - pb, k-pb);
    else
        return a[pa-1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int total = nums1Size + nums2Size;
    if(total%2 != 0)
        return findKth(nums1, nums1Size, nums2, nums2Size, total/2+1);
    else
        return (findKth(nums1, nums1Size, nums2, nums2Size, total/2)
                + findKth(nums1, nums1Size, nums2, nums2Size, total/2+1))/2;
}

int main()
{
    int A1[] = {2,5,8};
    int A2[] = {1,4,6,7};
    int N1 = sizeof(A1)/sizeof(A1[0]);
    int N2 = sizeof(A2)/sizeof(A2[0]);
    int M = findMedianSortedArrays(A1, N1, A2, N2);
    // the M should be 5.5
    printf("%d\n", M);

    return 0;
}