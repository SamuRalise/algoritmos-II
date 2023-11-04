#include <iostream>

using namespace std;

int main()
{
    int *v = NULL;
    int *p = NULL;
    int tam, i;
    int cont = 0;

    cin >> tam;
    
    v = new int[tam];

    p = v;

    for(i = 0; i < tam; i++)
    {
        cin >> *p;
        p++;
    }

    p = v;

    for(i = 0; i < tam; i++)
    {
        if(*p >= 0 && *p % 2 == 0)
        {
            cont++;
        }
        p++;
    }

    cout << cont << endl;

    return 0;
}