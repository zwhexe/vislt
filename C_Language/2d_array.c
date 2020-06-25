#include <stdio.h>
#include <stdlib.h>

void fun_arr(int array[][3], int (*p)[3], int row)
{
	printf("%d\n",array[1][1]);
	printf("%d\n",*(*(p+1)+1));
}

void fun_char(char str[], char *ps, char* pss[], char** pps )
{
	printf("%s\n", str);
	printf("%s\n", ps+1);
	printf("%s\n", *pss + 2);
	printf("%s\n", *pps + 2);
}

int main(int argc, const char* argv[])
{
	int array[4][3] = {{1,2,1},{2,3,2},{3,4,3},{4,5,4}};
	int (*p)[3] = array;
	fun_arr(array, p, 4);

	int i = 7;
	int *ptr = &i;
	int **pptr = &ptr;
	printf("\n%d\n\n", **pptr);

	char str[] = "Hello";
	char *ps = str;
	char **pps = &ps;
	fun_char(str, ps, pps, pps);

	return 0;
}