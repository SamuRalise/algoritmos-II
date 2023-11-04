#include <iostream>
using namespace std;

void insercao(int vetor[], int tam)
{
    int i, j;
    int chave;

    for (j = 1; j < tam; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] < chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
    return;
}
int main()
{
    int vetor[50];
    int i = 0;

    cin >> vetor[i];
    while (vetor[i] != 0)
    {
        i++;
        cin >> vetor[i];
    }

    insercao(vetor, i);

    for (int b = 0; b < i; b++)
    {
        if (b < i - 1)
            cout << vetor[b] << " ";
        else
            cout << vetor[b];
    }

    return 0;
}