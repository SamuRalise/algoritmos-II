#include <iostream>

using namespace std;

int main()
{
	int *v = NULL; //ponteiro de vetor
	int tam;
	int *p = NULL; //ponteiro aux

	cin >> tam; //tamanho do vetor
	v = new int[tam];
	p = v; //aponmtando para o início de v

	for(int b = 0; b < tam; b++)
	{
		cin >> *p; //entrada de dados
		p++;
	}

	p = v; //apontando pro início de v

	for(int i = 0; i < tam; i++)
	{
		cout << *p << " ";//mostrando o vetor v
		p++;
	}

	delete [] v;

	return 0;
}
