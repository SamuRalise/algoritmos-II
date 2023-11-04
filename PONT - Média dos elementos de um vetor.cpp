#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int *v;
    int *p;
    int tam, i;
    double media, soma = 0;

    cin >> tam; //tamanho do vetor
    
    v = new int[tam]; //alocando memória

    p = v; //apontando ponteiro

    for(i = 0; i < tam; i++)
    {
        cin >> *p; //lendo números
        p++;
    }

    p = v; //apontando para o início de v

    for(i = 0; i < tam; i++)
    {
        soma += *p; //fazendo a soma total
        p++;
    }

    media = soma / i; //média

    cout << fixed << setprecision(2) << media << endl;

    return 0;
}