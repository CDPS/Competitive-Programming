#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> g[100000];
vector<int> t[100000];
bool vs[100000];

void dfs(int u){
    vs[u] = true;
    for(int i=0;i<g[u].size();i++)
        if(!vs[g[u][i]])
            dfs(g[u][i]);
}

void dfst(int u){
    vs[u] = true;
    for(int i=0;i<t[u].size();i++)
        if(!vs[t[u][i]])
            dfst(t[u][i]);
}

int main(){

    cin >> n >> m;

    int u, v;
    for(int i=0;i<m;i++){
        cin >> u >> v; u--;v--;
        g[u].push_back(v);
        t[v].push_back(u);
    }

    dfs(0);

    for(int i=0;i<n;i++){
        if(!vs[i]){
            cout << "NO" << '\n';
			cout << 1 << " " << i + 1 << '\n';
			return 0;
        }
        vs[i] = false;
    }

    dfst(0);

    for(int i=0;i<n;i++){
        if(!vs[i]){
            cout << "NO" << '\n';
			cout << i + 1 << " " << 1 << '\n';
			return 0;
        }
    }

    cout << "YES" << "\n";

    return 0;
}

