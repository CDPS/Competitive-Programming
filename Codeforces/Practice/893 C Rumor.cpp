#include <bits/stdc++.h>

using namespace std;

vector<int> g[100000];

int   cost[100000];
bool vs[100000];

int dfs(int u){
    vs[u] = true;
    int mini = cost[u];
    for(int i=0;i<g[u].size();i++){
        if(!vs[g[u][i]])
            mini = min(mini, dfs(g[u][i]));
    }
    return mini;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, m, u, v;

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> cost[i];

    for(int i=0;i<m;i++){
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
        if(!vs[i])
            ans += dfs(i);

    cout << ans << "\n";

    return 0;
}

