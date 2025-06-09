#include <bits/stdc++.h>

using namespace std;

int n, m;

int color    [100000];
vector<int> g[100000];

bool bipartite = true;

void dfs(int u){
    for(int i=0;i<(int)g[u].size();i++){
        if(color[g[u][i]]== -1)
            color[g[u][i]] = !color[u], dfs(g[u][i]);
        if(color[g[u][i]] == color[u]) bipartite = false;
    }
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++) color[i] = -1;

    int u, v;
    for(int i=0;i<m;i++){
        cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<n;i++)
        if(color[i] == -1)
            color[i] = 0,dfs(i);

    if(!bipartite){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    for(int i=0;i<n;i++)
        cout << color[i]  + 1 << " \n"[i==n-1];

    return 0;
}

