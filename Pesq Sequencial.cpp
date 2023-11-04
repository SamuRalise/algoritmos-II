#include <iostream>

using namespace std;

int main()
{
	int vet[100];
	int i = 0;
	int x, tam, pos;
	bool flag;
	
	flag = false;
	cin >> vet[i];
	while(vet[i] != -1)
	{
		i++;
		cin >> vet[i];
	}
	tam = i;
	
	cin >> x;

	for(int i = 0; i < tam; i++)
	{
		if(vet[i] == x)
		{
			pos = i;
			flag = true;
		}
	}

	if(flag)
		cout << x << " encontrado na posicao " << pos;
	else
		cout << x << " nao encontrado";

	return 0;
}