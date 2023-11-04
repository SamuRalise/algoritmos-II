#include <iostream>
#include <cstring>

using namespace std;

struct info
{
    char nome[100];
    int idade;
    float peso;
    float altura;
};
struct dado
{
    info atleta;
    int k;
    int status;
};
int h1(int k, int m)
{
    int res;

    res = k % m;

    if (res < 0)
        res += m;

    return res;
}
int h2(int k, int m)
{
    int res;

    res = 1 + (k % (m - 1));
    if (res < 0)
        res += m;
    return res;
}
int dhash(int k, int m, int i)
{
    return (h1(k, m) + i * h2(k, m)) % m;
}
int hash_insert(dado t[], int m, int k)
{
    int j;
    int i = 0;
    do
    {
        j = dhash(k, m, i);
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
        j = dhash(k, m, i);
        if (t[j].k == k)
            return j;
        i++;
    } while (t[j].status != 0 && i < m);
    return -1;
}
int hash_remove(dado t[], int m, int k)
{
    int j;

    j = hash_search(t, m, k);
    if (j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;

        return j;
    }
    else
        return -1;
}
int main()
{
    int m, pos, op;
    dado T[100];
    char nome[50], x[50];
    int i, k;

    cin >> m;

    for (i = 0; i < m; i++)
    {
        T[i].k = -1;
        T[i].status = 0;
    }

    cin >> op;
    while (op != 5)
    {
        k = 0;
        switch (op)
        {
        case 1:
            cin.ignore();
            cin.getline(nome, 50);
            for (int b = 0; b < strlen(nome); b++)
                k += (int)nome[b];
            pos = hash_insert(T, m, k);
            strcpy(T[pos].atleta.nome, nome);
            cin >> T[pos].atleta.idade;
            cin >> T[pos].atleta.peso;
            cin >> T[pos].atleta.altura;
            break;
        case 2:
            cin.ignore();
            cin.getline(x, 50);
            for (int b = 0; b < strlen(x); b++)
                k += (int)x[b];
            pos = hash_search(T, m, k);
            if (pos == -1)
                cout << x << " nao encontrado" << endl
                     << endl;
            else
            {
                cout << "Nome: " << T[pos].atleta.nome << endl;
                cout << "Idade: " << T[pos].atleta.idade << endl;
                cout << "Peso: " << T[pos].atleta.peso << endl;
                cout << "Altura: " << T[pos].atleta.altura << endl
                     << endl;
            }
            break;
        case 3:
            cin.ignore();
            cin.getline(x, 50);
            for (int b = 0; b < strlen(x); b++)
                k += (int)x[b];
            hash_remove(T, m, k);
            break;
        case 4:
            for (int b = 0; b < m; b++)
            {
                if (T[b].status == 1)
                {
                    cout << "Nome: " << T[b].atleta.nome << endl;
                    cout << "Idade: " << T[b].atleta.idade << endl;
                    cout << "Peso: " << T[b].atleta.peso << endl;
                    cout << "Altura: " << T[b].atleta.altura << endl
                         << endl;
                }
            }
            break;
        }
        cin >> op;
    }
    return 0;
}
