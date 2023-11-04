#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista; //"ponteiro" p/ lista
    list<int>::iterator p, v, aux;         //"ponteiro" para aux
    int x, y; // aux p/ leitura

    cin >> x;
    while (x != -1) // incerindo os valores na lista
    {
        lista.push_front(x);
        cin >> x;
    }

    cin >> x >> y;
    
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p == x)
        {
            p++;
            lista.insert (p, y);
            break;
        }
    }

    while(!lista.empty()) // mostrando lista e esvaziando
    {
        cout << *lista.begin() << " ";
        lista.pop_front();
    }

    return 0;
}