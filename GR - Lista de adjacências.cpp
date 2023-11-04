#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v;    // vertice de adjacente
    int peso; // peso da aresta
};
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    no aux;

    aux.v = v;
    aux.peso = p;

    adj[u].push_back(aux);

    if (orientado == 0)
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}
void mostrandoGrafo(list<no> adj[], int V)
{
    list<no>::iterator p;

    for (int i = 0; i < V; ++i)
    {
        cout << i << " ";
        for (p = adj[i].begin(); p != adj[i].end(); p++)
        {
            cout << i << " " << p->v << " " << p->peso << endl;
        }
    }
}
int main()
{
    int V, orientado;
    int u, v, p;
    list<no> adj[5];
    list<no>::iterator q;

    cin >> V;
    cin >> orientado;

    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }

    // mostrandoGrafo(adj, V);
    for (int i = 0; i < V; ++i)
    {
        for (q = adj[i].begin(); q != adj[i].end(); q++)
        {
            cout << i << " " << q->v << " " << q->peso << endl;
        }
    }

    return 0;
}