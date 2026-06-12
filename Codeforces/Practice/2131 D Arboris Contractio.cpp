#include <bits/stdc++.h>

using namespace std;

int t, n, u, v;

int solve(){

    cin >> n;

    vector<int> in_degree(n + 1, 0);
    vector<vector<int> > g(n + 1);

    for(int i=0; i < n - 1; i++){
        cin >> u >> v;
        in_degree[u]++;
        in_degree[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> leaf_count(n + 1, 0);
    for(int i= 1; i <=n ; i++)
        if(in_degree[i] == 1)
            leaf_count[  g[i][0] ] ++;

    int total_leaf = 0, maxi_leaf  = 0;
    for(int i= 1; i <=n ; i++){
        total_leaf += leaf_count[i];
        maxi_leaf = max(maxi_leaf,leaf_count[i] );
    }

    return (n == 2) ? 0 : total_leaf - maxi_leaf;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
