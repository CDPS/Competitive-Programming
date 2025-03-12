#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int,int>> pq;
vector<int> g[100001];
int dist[100001];

void dfs(int u){
    pq.push({dist[u], u});
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(dist[v]==0){
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, src, trg, u, v ;
    cin >> t;

    while(t--){

        cin >> n >> src >> trg;

        for(int i=1;i<=n;i++) g[i].clear(), dist[i] = 0;

        for(int i=0;i<n-1;i++){
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }

        dist[trg] = 1;
        dfs(trg);

        while(!pq.empty())
            cout << pq.top().second << " ", pq.pop();
        cout << "\n";
    }
    return 0;
}
