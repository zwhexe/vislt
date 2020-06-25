#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1e6

clock_t start, stop;//clock_t is return type of clock_t
double duration;	//unit is second

double f1(int n, double a[], int x)
{
	int i;
	double p = a[0];
	for(i=1; i<n; i++)
		p += a[i]*pow(x, i);
	return p;
}

double f2(int n, double a[], int x)
{
	int i;
	double p = a[n];
	for(i=n; i>0; i--)
		p = a[i-1] + x*p;
	return p;
}

int main(int argc, const char *argv[])
{	
	int n = 10;
	int x = 1.1;
	double a[n];
	double ans;
	for(int i=0; i<n; i++)
		a[i] = (double)i;

	double(*pf[])(int, double [], int) = {f1, f2};
	
	for(int i=0; i<2; i++){
		start = clock();
		int j = 0;
		while(j<MAX){
			ans = (*pf[i])(n, a, x);
			j++;
		}
		stop = clock();

		duration = ((double)(stop - start))/(CLK_TCK*MAX);
		printf("duration%d = %6.2e\n", i+1, duration);
	}

	return 0;
}