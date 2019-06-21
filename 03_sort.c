#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
int sort(int *mass, int start, int end ) 
{
    int temp = 0;
	int i = start, j = end, d, beh = mass[(start + end) / 2];
	while (i <= j) {
		for (; mass[i] < beh; i++);
		for (; mass[j] > beh; j--);
		if (i <= j) 
		{
			d = mass[i];
			mass[i++] = mass[j];
			mass[j--] = d;
			temp++;
		}
		temp++;
	}
	if (start < j) temp+=sort(mass, start, j);
	if (i < end) temp+=sort(mass, i, end);
	return temp;
}


int main()
{
	srand(time(0));
	clock_t start, stop;
	unsigned long t;
	double rez, sr_rez = 0;
	int n[15] = { 1,2,3,4,5,10,15,20,25,30,50,75,100,250,500 };
	for (int f = 0; f < 15; f++)
	{
		int* a;
		a = (int*)malloc(n[f] * sizeof(int));
		start = clock();
		for (int j = 0; j < 1000; j++)
		{
			for (int i = 0; i < n[f]; i++)
			{
				a[i] = rand() % 10000 - 8000;
			}
			rez += sort(a,0, n[f]);
		}
		stop = clock();
		printf("%d\n %f \n", n[f], rez / 1000);
		rez = 0;
		double clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
		printf("%f \n", clock_rez * 100000);
		start, stop = 0;
		clock_rez = 0;
	}
	int g[100];

	for (int i = 0; i < 100; i++)
		g[i] = i;

	double clock_rez = 0;
	start = clock();
	rez = sort(g, 0,100);
	stop = clock();
	clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
	printf("%f \n", rez);
	printf("%f \n", clock_rez * 100000000);
	rez = 0;
	for (int i = 0; i < 100; i++)
		g[i] = 100 - i;

	clock_rez = 0;
	start = clock();
	rez = sort(g,0, 100);
	stop = clock();
	clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
	printf("%f \n", rez);
	printf("%f \n", clock_rez * 100000000);
}



