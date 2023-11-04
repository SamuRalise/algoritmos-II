#include <iostream>
#include <list>
#include <climits>

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
void bfs(list<no>adj[], int nVertices, int s)
{
    char state[10];
    int pai[10];
    list<int> Q;
    list<no>::iterator p;
    int v, u;


    for(u = 0; u < nVertices; u++)
        if(u != s)
        {
            state[u] = 'u';
            pai[u] = -1;
        }
    state[s] = 'd';
    pai[s] = -1;
    Q.push_back(s);

    while(!Q.empty())
    {
        u = *Q.begin();
        Q.pop_front();
        cout << u << endl;
        for(p = adj[u].begin(); p != adj[u].end(); p++)
        {
            v = p->v;
            cout << u << " " << v << endl;
            if(state[v] == 'u')
            {
                state[v] = 'd';
                pai[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 'p';

    }    
}
void prim(list<no>adj[], int nVertices, int start)
{
    bool intree[10];
    int distance[10];
    int parent[10];
    list<no>::iterator q;
    int weight, dist, v, destino, soma = 0;
    
    for(int u = 0; u < nVertices; u++)
    {
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
    distance[start] = 0;
    v = start;
    while(intree[v] == false)
    {
        intree[v] = true;
        for(q = adj[v].begin(); q != adj[v].end(); q++)
        {
            destino = q->v;
            weight = q->peso;
            if(distance[destino] > weight && intree[destino] == false)
            {
                distance[destino] = weight;
                parent[destino] = v;
            }
        }
        v = 0;
        dist = INT_MAX;
        for(int u = 0; u < nVertices; u++)
        {
            if(intree[u] == false && dist > distance[u])
            {
                dist = distance[u];
                v = u;
            }
        }
    }
    for(int u = 0; u < nVertices; u++)
    {
        soma += distance[u];
    }
    
     for(int u = 1; u < nVertices; u++)
    {
        cout << parent[u] << " " << u << endl;
    }
    
    cout << "Custo: " << soma << endl;
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
    int nVertices, s, orientado;
    int u, v, p;
    list<no> adj[10];
    list<no>::iterator q;

    cin >> nVertices;
    cin >> orientado;
    cin >> s;

    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }

    // mostrandoGrafo(adj, V);
    cout << "Arvore Geradora Minima:" << endl;
    //bfs(adj, nVertices, s);
    prim(adj, nVertices, s);
    

    return 0;
}

// Jhonny é um lindo, eu daria o cu para ele fácil 