#include <iostream>
#include <algorithm>
#include <fstream>
#include<vector>

using namespace std;

#define FI "test1.inp"


vector<vector<int>> adj;// danh sách kề vào
vector<bool> visited;// Danh sách đã đỉnh đã thăm
vector<int> tree;//Chứa cây 
vector<pair<int, int>> adjtree;// chứa danh sách kề của cây


void dfs_spanningtree(int s)
{
    visited[s] = true; 
    tree.push_back(s);
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            adjtree.push_back({s, u});
            dfs_spanningtree(u);
            
        }
    }
}

int main()
{
    ifstream fi(FI);

    int n, m;

    fi >> n >> m;
    fi.ignore();

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    

    int u, v;
    for (int i = 0; i < m; i++)
    {
        fi >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_spanningtree(1);

    cout << adjtree.size() << endl;
    for (auto [u, v] : adjtree)
    {
        cout <<u<<" "<<v<< endl;
    }

    return 0;
} 