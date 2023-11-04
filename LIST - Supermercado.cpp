#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista)
{
    list<int>::iterator p; //"ponteiro" para varrer a lista
    int cont = 0;
    // varrendo a lista, para contar os nós
    for (p = lista.begin(); p != lista.end(); p++)
        cont++;

    return cont;
}
int main()
{
    list<int> estoque, venda; //"ponteiro" p/ lista
    list<int>::iterator p; //"ponteiro" para aux
    int x, op, n;             // aux p/ leitura
    int res;                  // resultado da soma

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> op;

        switch (op)
        {
        case 1:
            cin >> x;
            estoque.push_back(x); // incerindo no estoque
            break;
        case 2:
            p = estoque.begin();
            venda.push_front(*p); // incerindo na venda
            estoque.pop_front();// removendo do estoque
            break;
        }
    }

    cout << "Estoque: ";
    for(p = estoque.begin(); p != estoque.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    cout << "Venda: ";
    for(p = venda.begin(); p != venda.end(); p++)
    {
        cout << *p << " ";
    }
    while (!estoque.empty()) // esvaziando lista
    {
        estoque.pop_front();
    }
    while (!venda.empty()) // esvaziando lista
    {
        venda.pop_front();
    }

    return 0;
}
