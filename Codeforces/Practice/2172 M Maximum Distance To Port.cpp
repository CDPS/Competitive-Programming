#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int    a[200001];
int  ans[200001];
int dist[200001];

bool v[200001];
vector<int> g[200001];

void bfs(int x){

    queue<int> q;

    q.push(x);
    v[x] = true;
    dist[x] = 0;
    while(!q.empty()){

        int u = q.front(); q.pop();
        for(int i=0;i < g[u].size();i++)
            if(!v[g[u][i]])
                v[g[u][i]] = true , dist[g[u][i]] = dist[u] + 1, q.push(g[u][i]);
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;

    for(int i=1;i<=n;i++)
        cin >> a[i];

    int u, v;
    while(m--){
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    bfs(1);
    for(int i=1;i<=n;i++)
        ans[ a[i] ] = max(ans[ a[i] ], dist[i] );
    for(int i=1;i<=k;i++)
        cout << ans[i] << " \n"[i==k];

    return 0;
}
