#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int t, n;

int g[300002][2];
ll  cost[300002];
ll   ans[300002];

ll dfs1(int x){

    if(g[x][0] == 0 && g[x][1] ==0) return cost[x] = 1;

    return cost[x] =(3 + dfs1(g[x][0]) + dfs1(g[x][1])) % mod;
}

void dfs2(int x, ll acc) {

    ans[x] = (cost[x] + acc) % mod;

    if(g[x][0] != 0) dfs2(g[x][0], ans[x]);
    if(g[x][1] != 0) dfs2(g[x][1], ans[x]);
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> g[i][0] >> g[i][1];

    dfs1(1);
    dfs2(1, 0);

    for(int i=1; i <=n ; i ++ )
        cout<< ans[i] << " \n"[i==n];

}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
