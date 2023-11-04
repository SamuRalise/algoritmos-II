#include <iostream>
#include <cmath>

using namespace std;

void quickSort(int vetor[], int i, int j)
{
	int trab, esq, dir, pivo;

	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)];
	do
	{
		while(vetor[esq] < pivo)
			esq++;
		while(vetor[dir] > pivo)
			dir--;
		if(esq <= dir)

		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}while(esq <= dir);

	if(dir - i >= 0)
		quickSort(vetor, i, dir);
	if(j - esq >= 0)
		quickSort(vetor, esq, j);

}
int main()
{
	int vetor[100];
	int i = 0;

	cin >> vetor[i];
	while(vetor[i] != -1)
	{
		i++;
		cin >> vetor[i];
	}

	quickSort(vetor, 0, i - 1);

	for(int b = 0; b < i; b++)
		cout << vetor[b] << " ";

	return 0;
}
