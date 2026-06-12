#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[100001];
vector<int> t[100001];
int        vs[100001];
int      curr[100001];
int  expected[100001];

void rebuild_graph(int u, int level, int even_parent, int odd_parent){

    vs[u] = true;

    if(level%2)
        t[odd_parent].push_back(u), odd_parent = u;
    else
        t[even_parent].push_back(u), even_parent = u;

    for(int i = 0; i< g[u].size();i++){
        if(vs[g[u][i]]) continue;
        rebuild_graph(g[u][i], level + 1, even_parent, odd_parent);
    }
}

vector<int> ans;
void dfs(int u, int change){

    if(change % 2)
        curr[u] = !curr[u];

    bool check = curr[u] != expected[u] ;
    if(check)
        ans.push_back(u);

    for(int i = 0; i < t[u].size(); i++)
        dfs(t[u][i], change + check );
}

void solve(){

    cin >> n;

    int x, y;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
        cin >> curr[i];
    for(int i=1;i<=n;i++)
        cin >> expected[i];

    rebuild_graph(1, 0, 0, 0);

    for(int i=0;i<t[0].size();i++)
        dfs(t[0][i], 0);

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
