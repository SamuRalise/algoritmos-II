#include <iostream>
#include <list>
#include <cstring>

using namespace std;
struct dados
{
    char nome[50];
    int d;
};
int main()
{
    list<dados> lista; //"ponteiro" p/ lista
    list<dados>::iterator p, v, aux;         //"ponteiro" para aux
    int d, n; // aux p/ leitura
    dados info;
    char pagou[50];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(info.nome, 50);
        cin >> info.d;
        lista.push_back(info);
    }
    
    cin.ignore();
    cin.getline(pagou, 50);
    
    for(aux = lista.begin(); aux != lista.end(); aux++)
    {
        if(strcmp(aux->nome, pagou) == 0)
            {
               aux =  lista.erase(aux);
            }
    }

    for(aux = lista.begin(); aux != lista.end(); aux++)
    {
        cout << aux->nome << endl;
        cout << aux->d << endl;
    }

    return 0;
}