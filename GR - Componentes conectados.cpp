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
int bfs(list<no>adj[], int nVertices, int s)
{
    char state[10];
    int pai[10];
    list<int> Q;
    list<no>::iterator p;
    int v, u, aux = -1, cont = 0;


    for(u = 0; u < nVertices; u++)
        if(u != s)
        {
            state[u] = 'u'; //undiscovered
            pai[u] = -1; //sem pai
        }
    state[s] = 'd'; //discovered
    pai[s] = -1;
    Q.push_back(s);

    while(!Q.empty())
    {
        u = *Q.begin();
        Q.pop_front();
        if(u != aux)
        {
            cont++;
            aux = u;
        }
        for(p = adj[u].begin(); p != adj[u].end(); p++)
        {
            v = p->v;
            cout << u << " " << v << endl;
            if(state[v] == 'u')
            {
                state[v] = 'd'; //discovered
                pai[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 'p'; //processed

    }
    if(aux == nVertices)
        return 1;
    else
        return 0;    
}
void mostrandoGrafo(list<no> adj[], int nVertices)
{
    list<no>::iterator p;

    for (int i = 0; i < nVertices; ++i)
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
    int nVertices, s, orientado = 0;
    int u, v, p = 1, res;
    list<no> adj[10];
    list<no>::iterator q;

    cin >> nVertices;
    cin >> s;

    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v;
    }
    
    res = bfs(adj, nVertices, s);

    if(res == 1)
        cout << "Conexo" << endl;
    else
        cout << "Nao conexo" << endl;

    return 0;
}