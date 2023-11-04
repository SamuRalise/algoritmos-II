#include <iostream>

using namespace std;

int main()
{
    int *v;
    int *p;
    int tam, i;
    double maior = -999;

    cin >> tam; //tamanho do vetor
    
    v = new int[tam]; //alocando memória

    p = v; //apontando para endereço de v

    for(i = 0; i < tam; i++)
    {
        cin >> *p;//lendo os elementos
        p++;
    }

    p = v; //apontando para o v

    for(i = 0; i < tam; i++)
    {
        if(maior < *p)//if para descobrir o maior número
        {
            maior = *p;
        }
        p++;
    }

    cout << maior << endl;

    return 0;
}