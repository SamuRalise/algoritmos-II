#include <iostream>
#include <list>
#include <climits>
#include <cstring>

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
void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
    bool intree[10];
    int distance[10];
    int parent[10];
    //int caminho[10];
    list<int> caminho;
    list<no>::iterator q;
    int weight, dist, v, destino, aux;
    
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
            if(distance[destino] > distance[v] + weight)
            {
                distance[destino] =distance[v] + weight;
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
    /*int b = 0;
    aux = end;
    while(aux != start)
    {
        caminho[b] = aux;
        aux = parent[aux];
        b++;
    }
    cout << "Menor caminho: ";
    for(int u = b; u >= 0; u--)
    {
        cout << caminho[u] << " ";
    }
    cout << endl;
    cout << "Custo: " << distance[end] << endl;*/
    aux = end;
    do
    {
        caminho.push_front(parent[aux]);
        aux = parent[aux];
    } while (aux != -1);
    
    cout << "Menor caminho: ";
    while(!caminho.empty())
    {
        cout << *caminho.begin() << " ";
        caminho.pop_front();
    }
    cout << endl;
    cout << "Custo: " << distance[end] << endl;
}
int main()
{
    int nVertices, s, orientado, destino;
    int u, v, p;
    list<no> adj[10];
    list<no>::iterator q;

    cin >> nVertices;
    cin >> orientado;
    cin >> s;
    cin >> destino;

    cin >> u >> v >> p;
    while (u != -1 && v != -1 && p != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }

    dijkstra(adj, nVertices, s, destino);
    

    return 0;
}