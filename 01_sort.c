#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TipStep(int step)
{
	step = (int)(step / 1.247);
	if (step < 1)
		step = 1;
	return step;
}

int sort(int mass[], int Length)
{
    int temp = 0;
	int step = Length;
	while (1)
	{
		step = TipStep(step);
		int fin = 0;
		for (int i = 0; i < Length - step; i++)
		{
			int j = i + step;
			if (mass[i] > mass[j])
			{
				int t = mass[i];
				mass[i] = mass[j];
				mass[j] = t;
				fin = 1;
				temp++;
			}
			temp++;
		}
		if (step == 1 && !fin)
			break;
	}
	return temp;
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
rez += sort(a,n[f]);
}
stop = clock();
printf("%d\n %f \n",n[f],rez/1000);
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*100000);
start ,stop = 0;
clock_rez = 0;
}
int g [100];

for (int i =0;i <100;i++)
g[i] = i;

double clock_rez = 0;
start = clock();
rez = sort(g,100) ; 
stop = clock();
clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",rez);
printf("%f \n",clock_rez*100000000);
rez = 0;
for (int i =0;i <100;i++)
    g[i] = 100 - i;

clock_rez = 0;
start = clock();
rez = sort(g,100) ; 
stop = clock();
clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",rez);
printf("%f \n",clock_rez*100000000);
}
