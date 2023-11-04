#include <iostream>
#include <list>
#include <climits>
#include <cstring>

using namespace std;

struct no
{
    int v;    // vértice adjacente
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

void ordenacao_topologica(int f[], int nVertices)
{
    int i, j, order[10];
    int chave, aux;

    // Inicializa o array order com os vértices de 0 a nVertices-1
    for (int u = 0; u < nVertices; u++)
    {
        order[u] = u;
    }

    // Ordenação por inserção usando o array f como chave
    for (j = 1; j < nVertices; j++)
    {
        chave = f[j];
        aux = order[j];
        i = j - 1;
        while ((i >= 0) && (f[i] < chave))
        {
            f[i + 1] = f[i];
            order[i + 1] = order[i];
            i = i - 1;
        }
        f[i + 1] = chave;
        order[i + 1] = aux;
    }

    // Imprime a ordem topológica dos vértices
    for (int u = 0; u < nVertices; u++)
    {
        cout << order[u] << " ";
    }

    return;
}

void dfs_visit(int u, list<no> adj[], int &time, int d[], int pi[], int f[], char color[])
{
    list<no>::iterator v;

    color[u] = 'G'; // Marca o vértice como visitado (cinza)
    time++;
    d[u] = time; // Marca o tempo de descoberta do vértice

    // Percorre todos os vértices adjacentes a u
    for (v = adj[u].begin(); v != adj[u].end(); v++)
    {
        if (color[v->v] == 'W') // Se o vértice não foi visitado (branco)
        {
            pi[v->v] = u; // Define o pai do vértice
            dfs_visit(v->v, adj, time, d, pi, f, color); // Chama recursivamente a função para o vértice adjacente
        }
    }

    time++;
    color[u] = 'B'; // Marca o vértice como visitado completamente (preto)
    f[u] = time; // Marca o tempo de finalização do vértice
}

void dfs(list<no> adj[], int nVertices)
{
    char color[10];
    int d[10], pi[10], f[10];
    int time;
    list<no>::iterator q;

    // Inicializa os arrays color, pi, d e f
    for (int u = 0; u < nVertices; u++)
    {
        color[u] = 'W'; // Define todos os vértices como não visitados (branco)
        pi[u] = -1; // Define o pai de cada vértice como -1
    }

    time = 0;

    // Chama a função dfs_visit para cada vértice não visitado
    for (int u = 0; u < nVertices; u++)
    {
        if (color[u] == 'W')
            dfs_visit(u, adj, time, d, pi, f, color);
    }

    ordenacao_topologica(f, nVertices); // Realiza a ordenação topológica com base no array f
}

int main()
{
    int nVertices, orientado;
    int u, v, p = 1;
    list<no> adj[10];

    // Lê o número de vértices, se o grafo é orientado ou não
    cin >> nVertices;
    cin >> orientado;

    // Lê as arestas do grafo
    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v;
    }

    dfs(adj, nVertices); // Chama a função DFS para realizar a ordenação topológica

    return 0;
}