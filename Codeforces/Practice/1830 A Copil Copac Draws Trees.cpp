#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> g[200001];
int level[200001];

void dfs(int u, int prev){
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i].first;
        if(level[v] == 0){
            level[v] = level[u] + ( prev >= g[u][i].second );
            dfs(v, g[u][i].second);
        }
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, u , v;
    cin >> t;
    while(t--){

        cin >> n;

        for(int i=0; i<=n; i++)
            level[i] = 0, g[i].clear();

        for(int i=0;i<n-1;i++){
            cin >> u >> v;
            g[u].push_back({v,i+1}); g[v].push_back({u,i+1});
        }

        level[1] = 1;
        dfs(1, 0);

        int ans = -1;
        for(int i=1;i<=n;i++)
            ans = max(ans, level[i]);

        cout << ans << "\n";
    }
    return 0;
}
