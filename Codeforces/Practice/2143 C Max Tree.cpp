#include <bits/stdc++.h>

using namespace std;

int t, n;

vector<int> g[200001];
int    degree[200001];
int     level[200001];

void bfs(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0;i<g[u].size();i++){
            int v= g[u][i];
            if(level[v] < level[u] + 1)
                q.push(v), level[v] = level[u] + 1;
        }
    }
}

void solve(){

    cin >> n;

    for(int i=0;i<=n;i++)
        g[i].clear(), degree[i] = 0, level[i]=0;

    int u, v, x, y;
    for(int i=0;i<n-1;i++){
        cin >> u >> v >> x >> y;
        if(x  > y)
            g[v].push_back(u), degree[u]++;
        else
            g[u].push_back(v), degree[v]++;
    }

    for(int i=1;i<=n;i++)
        if(degree[i]==0)
            bfs(i);

    vector<pair<int,int>> ans(n+1);
    for(int i=1;i<=n;i++)
        ans[i] = {level[i], i };

    sort(ans.begin(), ans.end());
    for(int i=1;i<=n;i++)
        level[ ans[i].second ] = i;

    for(int i=1;i<=n;i++)
        cout << level[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
