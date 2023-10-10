#include <bits/stdc++.h>

using namespace std;

int n,m;

int cats[100001];
vector<int> g[100001];
bool visit[100001];

int dfs(int u,int acc){

    visit[u] = 1;
    if(acc > m) return 0;
    if(g[u].size()== 1 && u != 1 ) return 1;

    int res =0;
    for(int i =0;i < g[u].size();i++){
        int v = g[u][i];
        if(!visit[v])
            res += dfs(v, cats[v] == 0? 0: acc + cats[v] );
    }
    return res;
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> cats[i+1];
    }

    int x,y;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res = dfs(1,cats[1]);

    cout  << res << "\n";
    return 0;
}
