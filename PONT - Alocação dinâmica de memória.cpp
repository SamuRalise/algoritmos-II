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
	double soma = 0;

	v = new dado;

	for(int i = 0; i < 4; i++)
	{
		cin >> v -> nota[i];
		soma += v -> nota[i];
	}
	v -> media = soma / 4.0;

	cout << fixed << setprecision(2) << v -> media;

	delete v;

	return 0;
}
