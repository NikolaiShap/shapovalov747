#include <stdlib.h>
#include <stdio.h>


void ter(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* dejkstri(int** mass, int Length, int tmp_)
{
	int* mass_ = (int*)malloc(Length * sizeof(int));
	int* TempMass = (int*)malloc(Length * sizeof(int));
	for (int i = 0; i < Length; i++) {
		if (i == tmp_)
			mass_[i] = 0;
		else
			mass_[i] = 1000;
	}
	int t, min_, x;
	for (int i = 0; i < Length; i++)
	{
		TempMass[i] = 1;
	}
	do {
		min_ = 1000;
		x = 1000;
		for (int i = 0; i < Length; i++) {
			if ((TempMass[i] == 1) && (mass_[i] < 1000)) {
				min_ = mass_[i];
				x = i;
			}
		}
		if (x != 1000) {
			for (int i = 0; i < Length; i++) {
				if (mass[x][i] > 0) {
					t = min_ + mass[x][i];
					if (t < mass_[i])
						mass_[i] = t;
				}
			}
			TempMass[x] = 0;
		}
	} while (x < 1000);
	return mass_;
}
int findMindCountour(int* TmpMass, int** mass, int n, int Length)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				mass[i][j] = 0;
			else {
				if (mass[i][j] == 0)
					mass[i][j] = 1000;
			}
		}
	}
	int temp = 0;
	int op = 0;
	int NeedSum = 0, tmp = n;
	for (int i = 0; i <= n - 1; i++)
		NeedSum += mass[TmpMass[i % tmp]][TmpMass[(i + 1) % tmp]];
	if (Length > NeedSum) {
		Length = NeedSum;
	}
	while (op < 119) {
		NeedSum = 0;
		int j = n - 2;
		while (j != -1 && TmpMass[j] >= TmpMass[j + 1])
			j--;
		if (j == -1)
			op = 119;
		int k = n - 1;
		while (TmpMass[j] >= TmpMass[k])
			k--;
		{
			ter(&TmpMass[j], &TmpMass[k]);
		}
		int l = j + 1, r = n - 1;
		while (l < r)
			ter(&TmpMass[l++], &TmpMass[r--]);
		for (int i = 0; i <= n - 1; i++)
			NeedSum += mass[TmpMass[i % tmp]][TmpMass[(i + 1) % tmp]];
		if (Length > NeedSum)
			Length = NeedSum;
		op++;
	};
	return Length;
}
int main()
{



	int LengthMass = 0;
	printf("Введите количетсво вершин ");
	scanf("%d", &LengthMass);
	int** mass = malloc(sizeof(int*) * LengthMass);
	for (int i = 0; i < LengthMass; i++) {
		mass[i] = malloc(sizeof(int) * LengthMass);
	}
	int g = 0;
	printf("Введите кол-во дорог ");
	scanf("%d", &g);
	for (int i = 0; i < g; ++i)
	{
		printf("Первый город, второй и расстояние между ними ");
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		mass[x][y] = w;

	}



	int* graph = (int*)malloc(LengthMass * sizeof(int));
	for (int i = 0; i < LengthMass; i++)
		graph[i] = i;
	int z = 1;
	for (int i = 0; i < LengthMass; i++) {
		for (int j = 0; j < LengthMass; j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	int v;
	printf("Введите начальную вершину\n");
	scanf(" %d", &v);
	int* Temp_ = dejkstri(mass, LengthMass, v - 1);
	for (int i = 0; i < LengthMass; i++) {
		if (Temp_[i] <= 9999) {
			printf("Минимальный путь %d в %d: %d\n", v, z, Temp_[i]);
		}
		z++;
	}
	int Task2 = findMindCountour(graph, mass, LengthMass, 9999);
	if (Task2 <= 9999) {
		printf("Контур минимальной длинны %d\n", Task2);
	}
	return 0;
}
