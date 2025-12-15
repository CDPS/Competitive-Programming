#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;

vector<int> g[49];
vector<int> curr;
bool vs[49];

vector<vector<int>> a[3];

void dfs(int u){
    curr.push_back(u);
    vs[u] = true;
    for(int i=0;i<g[u].size(); i++)
        if(!vs[g[u][i]])
            dfs(g[u][i]);
}

void solve(){

    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vs[i]){
            curr.clear();
            dfs(i);
            if(curr.size() > 3){
                cout << -1 << "\n";
                return;
            }
            a[curr.size()%3].push_back(curr);
        }
    }

    if(a[2].size() > a[1].size()){
        cout << -1 << "\n";
        return;
    }

    for(int i=0;i<a[0].size();i++)
        cout << a[0][i][0] << " " << a[0][i][1] << " " << a[0][i][2] << "\n";

    for(int i=0;i<a[2].size();i++){
        cout << a[2][i][0] << " " << a[2][i][1] << " " << a[1].back()[0] << "\n";
        a[1].pop_back();
    }

    for(int i=0;i<a[1].size();i+=3)
        cout << a[1][i][0] << " " << a[1][i+1][0] << " " << a[1][i+2][0] << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
