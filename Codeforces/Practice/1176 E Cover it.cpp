#include <bits/stdc++.h>

using namespace std;

int n, m;

int color    [200000];
vector<int> g[200000];

bool bipartite = true;

void dfs(int u){
    for(int i=0;i<(int)g[u].size();i++){
        if(color[g[u][i]]== -1)
            color[g[u][i]] = !color[u], dfs(g[u][i]);
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, m;

    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i=0;i<n;i++) color[i] = -1, g[i].clear();

        int u, v;
        for(int i=0;i<m;i++){
            cin >> u >> v; u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }


        color[0] = 0, dfs(0);

        int blacks=0, whites=0;
        for(int i=0;i<n;i++){
            if(color[i]) blacks++;
            else whites++;
        }

        int chosen = (blacks < whites);
        cout << min(blacks, whites) << "\n";
        for(int i=0;i<n;i++)
            if(color[i] == chosen)
                cout << i + 1 << " ";
        cout << "\n";
    }

    return 0;
}


