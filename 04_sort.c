#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int siftDown(int *arr, int root, int bottom)
{
 	int max;
	int tmp =0;	
	
 	while (root * 2 <= bottom)
	{
		if ((root * 2 == bottom) || (arr[root * 2] > arr[root * 2 + 1]))
		{tmp++;
			max = root * 2;
		}
		else
		{tmp++;
			max = root * 2 + 1;
		}
		
		if (arr[root] < arr[max]) 
		{ tmp++;
			int t = arr[root]; 
			arr[root] = arr[max];
			arr[max] = t;
			root = max;
			tmp++;
		}
		else 
		{
			tmp++;
			break;
		}
	}
	return tmp;
}

int sorting_Pyr(int *arr, int arr_len) //пирамидальная
{
	int tmp =0;
	for (int i = (arr_len / 2) ; i >= 0; i--)
		tmp += siftDown(arr, i, arr_len - 1);
	for (int i = arr_len - 1; i >= 1; i--)
	{
    		int t = arr[0];
    		arr[0] = arr[i];
    		arr[i] = t;
		tmp += siftDown(arr, 0, i - 1);
		tmp++;
	}
return tmp;
}


int main()
{
    srand(time(0));
  clock_t start,stop;
unsigned long t;
    double rez,sr_rez = 0;
int n[15] = {1,2,3,4,5,10,15,20,25,30,50,75,100,250,500};
for (int f = 0 ; f <15;f++)
{
int *a;
a = (int*)malloc(n[f] * sizeof(int));
start = clock();
for (int j = 0;j <1000;j++)
{
for (int i = 0;i < n[f]; i ++)
{
a[i] = rand()%10000 - 8000;
} 
rez += sorting_Pyr(a,n[f]);
}
stop = clock();
printf("%d\n %f \n",n[f],rez/1000);
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*100000);
start ,stop = 0;
clock_rez = 0;
}
	int g[100];

	for (int i = 0; i < 100; i++)
		g[i] = i;

	double clock_rez = 0;
	start = clock();
	rez = sorting_Pyr(g, 100);
	stop = clock();
	clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
	printf("%f \n", rez);
	printf("%f \n", clock_rez * 100000000);
	rez = 0;
	for (int i = 0; i < 100; i++)
		g[i] = 100 - i;

	clock_rez = 0;
	start = clock();
	rez = sorting_Pyr(g, 100);
	stop = clock();
	clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
	printf("%f \n", rez);
	printf("%f \n", clock_rez * 100000000);
}
