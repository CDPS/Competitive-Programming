#include <bits/stdc++.h>

using namespace std;

int n, m;

bool vs[100000];
vector<int> g[100000];

void dfs(int u){
    vs[u] = true;
    for(int i=0;i<(int)g[u].size();i++)
        if(!vs[g[u][i]])
            dfs(g[u][i]);
}

int main(){

    cin >> n >> m;

    int u, v;
    for(int i=0;i<m;i++){
        cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    vector<int> ans;

    for(int i=0;i<n;i++){
        if(!vs[i]){
            ans.push_back(i+1);
            dfs(i);
        }
    }

    cout << ans.size() - 1 << "\n";
    for(int i=1;i<ans.size();i++)
        cout << ans[0] << " " << ans[i] << "\n";

    return 0;
}
