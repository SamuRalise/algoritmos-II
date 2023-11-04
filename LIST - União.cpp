#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista1, lista2, lista3; //"ponteiro" p/ lista
    list<int>::iterator p, v, aux;    //"ponteiro" para aux
    int x, i = 0;                            // aux p/ leitura

    cin >> x;
    while (x != 0) // lendo lista 1
    {
        lista1.push_back(x);
        cin >> x;
    }
    cin >> x;
    while (x != 0) // lendo lista 2
    {
        lista2.push_back(x);
        cin >> x;
    }

    p = lista1.begin();
    v = lista2.begin();

   for(p = lista1.begin(); p != lista1.end(); i++)
   {
    	while(v == lista2.end())
    	{
        	lista3.push_back(*p);
        	p++;
    	}
    
        if (*p > *v)
        {
            lista3.push_back(*v);
            v++;
        }
        else if (*p < *v)
        {
            lista3.push_back(*p);
            p++;
        }
        else
        {
            lista3.push_back(*v);
            v++;
            p++;
        }
    }
    while (v != lista2.end())
    {
        lista3.push_back(*v);
        v++;
    }

   while (!lista3.empty()) // mostrando e esvaziando lista 3
    {
        cout << *lista3.begin() << " ";
        lista3.pop_front();
    }

    while (!lista1.empty()) // esvaziando lista 1
    {
        lista1.pop_front();
    }
    
    while (!lista2.empty()) // esvaziando lista 2
    {
        lista2.pop_front();
    }
    
    return 0;
}