#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<int> g[200001];
int     color[200001];

int bfs(int x){

    bool is_bipartite = true;

    queue<int> q;
    q.push(x);
    color[x] = 0;

    vector<int> acc(2);
    acc[0]++;
    while (!q.empty()) {

        int u = q.front(); q.pop();

        for (int v : g[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
                acc[color[v]]++;
            }
            is_bipartite &= color[u] != color[v];
        }
    }
    return is_bipartite * max( acc[0], acc[1]);
}

int u, v;
int solve(){

    cin >> n >> m;

    for(int i=0; i <=n; i++)
        color[i] = -1, g[i].clear();

    while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(color[i] == -1)
            ans+= bfs(i);
    }


    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve()  << "\n";

    return 0;
}
