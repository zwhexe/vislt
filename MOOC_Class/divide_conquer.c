#include <stdio.h>

int divide(int A[], int left, int right);

int main()
{
	int arr[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int ans;
	ans = divide(arr, 0, N-1);
	printf("%d\n", ans);

	return 0;
}


int divide(int A[], int left, int right)
{
	if (left == right) {
		if (A[left] > 0)
			return A[left];
		else
			return 0;
	}
	int maxLeft, maxRight;
	int maxLeftBorder, maxRightBorder;

	int leftBorder, rightBorder;
	int center, i;

	center = (left + right) / 2;
	maxLeft = divide(A, left, center);
	maxRight = divide(A, center+1, right);

	leftBorder = 0;
	maxLeftBorder = 0;
	for (i = center ; i >= left; i--) {
		leftBorder += A[i];
		if (leftBorder > maxLeftBorder)
			maxLeftBorder = leftBorder;
	}

	rightBorder = 0;
	maxRightBorder = 0;
	for (i = center + 1; i <= right; i++) {
		rightBorder += A[i];
		if (rightBorder > maxRightBorder)
			maxRightBorder = rightBorder;
	}
	int maxBorder = maxRightBorder + maxLeftBorder;
	return  (maxLeft > maxRight) ? (maxBorder > maxLeft ? maxBorder : maxLeft) : (maxBorder > maxRight ? maxBorder : maxRight);
}