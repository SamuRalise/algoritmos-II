#include <iostream>
using namespace std;

int fun(int vetor[], int tam)
{
    int i, j;
    int trab;
    bool troca;
    int limite, cont = 0, aux = 999;

    troca = true;
    limite = tam - 1;
    while (troca)
    {
        troca = false;
        for (i = 0; i < limite; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                if (trab != aux)
                {
                    cout << "New trab:" << trab << endl;
                    aux = trab;
                    cont++;
                }
                j = i;
                troca = true;
            }
        }
        limite = j;
    }

    return cont;
}
int main()
{
    int n;
    int vetor[50];
    int cont;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> vetor[i];
    }
    cont = fun(vetor, n);

    cout << "Contador:" << cont << endl;

    return 0;
}