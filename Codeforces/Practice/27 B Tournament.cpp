#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

int  indegree[51];
bool g[51][51];

vector<int> topoSort() {

    queue<int> q;
    vector<int> v;

    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        v.push_back(u);

        for(int v = 1; v<=n ;v++)
            if(g[u][v] && --indegree[v] == 0)
                q.push(v);
    }
    return v;
}

void solve(){

    cin >> n;
    m = n*(n-1)/2;

    for(int i=0, u, v;i<m-1;i++){
        cin >> u >> v;
        g[u][v] = 1;
        indegree[v]++;
    }

    vector<int> v = topoSort();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(!g[v[i]][v[j]]){
                cout << v[i] << " " << v[j] << "\n";
                return;
            }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
