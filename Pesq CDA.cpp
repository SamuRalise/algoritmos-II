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
	int vetor[20];
	int i = 0;
	int id, flag;

	cin >> vetor[i];
	while(vetor[i] != -1)
	{
		i++;
		cin >> vetor[i];
	}
	
	cin >> id;

	flag = binaria(vetor, i, id);

	if(flag > -1)
		cout << "Possui acesso";
	else
		cout << "Nao possui acesso";

	return 0;
}
