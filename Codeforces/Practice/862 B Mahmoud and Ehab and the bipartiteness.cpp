#include <bits/stdc++.h>

using namespace std;

int n, u, v;
long long blacks;
vector<int> g[100000];
int color[100000];

void dfs(int u, int c){
    color[u] = c;
    if(c==2){blacks++;}
    for(int i=0;i<g[u].size();i++)
        if(!color[g[u][i]])
            dfs(g[u][i], c==1? 2 : 1 );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 1);

    long long ans = 0;
    for(int i=0;i<n;i++){
        if(color[i]==1){
            long long  curr = 0;
            for(int j=0;j<g[i].size();j++)
                if( color[g[i][j]] == 2) curr++;
            ans+= blacks-curr;
        }
    }
    cout << ans << "\n";

    return 0;
}
