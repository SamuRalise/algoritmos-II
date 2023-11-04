#include <iostream>

using namespace std;

struct dado
{
    int k;
    int status;
};
int hash_aux(int k, int m)
{
    int res;

    res = k % m;

    if (res < 0)
        res += m;

    return res;
}
int hash1(int k, int i, int m)
{
    return (hash_aux(k, m) + i) % m;
}
int hash_insert(dado t[], int m, int k)
{
    int j;
    int i = 0;
    do
    {
        j = hash1(k, i, m);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;

            return j;
        }
        else
        {
            i++;
        }
    } while (i != m);

    return -1;
}
int hash_search(dado t[], int m, int k)
{
    int i = 0;
    int j;

    do
    {
        j = hash1(k, i, m);
        if (t[j].k == k)
            return j;
        i++;
    } while (t[j].status != 0 && i < m);
    return -1;
}
int main()
{
    int m, chave, pos;
    dado T[100];
    int i, k = 0;

    cin >> m;

    for (i = 0; i < m; i++)
    {
        T[i].k = -1;
        T[i].status = 0;
    }
    cin >> k;
    while (k != 0)
    {
        hash_insert(T, m, k);
        cin >> k;
    }
    cin >> chave;

    pos = hash_search(T, m, chave);

    if (pos == -1)
        cout << "Chave " << chave << " nao encontrada" << endl;
    else
        cout << "Chave " << chave << " encontrada na posicao " << pos << endl;

    return 0;
}
