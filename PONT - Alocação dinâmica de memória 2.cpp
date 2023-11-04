#include <iostream>
#include <iomanip>

using namespace std;


struct dado
{
	int nota[4];
	double media;
};
int main()
{
	dado *v = NULL;
	double soma, somaDaMedia = 0;
	int tam, b = 0;

	cin >> tam;
	v = new dado[tam];

	do
	{
		soma = 0;
		for(int i = 0; i < 4; i++)
		{
			cin >> v[b].nota[i];
			soma += v[b].nota[i];
		}
		v[b].media = soma / 4.0;

		b++;
	}
	while(b < tam);

	for(int i = 0; i < tam; i++)
	{
		somaDaMedia += v[i].media;
	}

	cout << fixed << setprecision(2) << somaDaMedia / (tam * 1.0);

	delete [] v;

	return 0;
}