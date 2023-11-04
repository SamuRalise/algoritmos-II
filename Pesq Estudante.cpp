#include <iostream>

using namespace std;

int binaria(int vetor[], int tamanho, int x)
{
	bool achou;
	int baixo, meio, alto;

	baixo = 0;
	alto = tamanho - 1;
	achou = false;
	while((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if(x < vetor[meio])
			alto = meio - 1;
		else
		{
			if(x > vetor[meio])
				baixo = meio + 1;
			else
				achou = true;
		}

	}
	if(achou)
		return meio;
	else
		return -1;
}
int main()
{
	int vetor[10000];
	int i = 0;
	int n, x, pos;

	cin >> n;
	while(i < n)
	{
		cin >> vetor[i];
		i++;
	}
	
	cin >> x;

	pos = binaria(vetor, i, x);

	if(pos > -1)
		cout << "Corredor " << pos;
	else
		cout << "Nao localizado";

	return 0;
}
