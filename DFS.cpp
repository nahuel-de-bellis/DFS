#include <iostream>
#include <vector>

using namespace std;

struct grafo
{
    int nodos, aristas;
    vector <vector <int> > adj;
    vector <bool> visitados;
    vector <int> recorrido;
    
    void leer()
    {
        int n1, n2;
        cin >> nodos >> aristas;
        adj.resize(nodos+1);
        visitados.resize(nodos+1, false);
        
        for(int i = 0;i<nodos;i++)
        {
            cin >> n1 >> n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        
        }
        
    }
    void DFS(int inicio)
    {
        visitados[inicio] = true;
        recorrido.push_back(inicio);
        
        for(int i = 0; i<adj[inicio].size();i++)
        {
            if(visitados[adj[inicio][i]] == false)
            {
                
                DFS(adj[inicio][i]);
            }
        }
        
        
        
    }
    
};


int main()
{
    grafo g;
    g.leer();
    g.DFS(1);
    
    for(int i = 0; i < g.recorrido.size();i++)
        {
            cout << g.recorrido[i] << " ";
            
        }
    
    
    return 0;
}
