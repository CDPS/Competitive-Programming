#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

bool g[101][101];
int degree[101];

int check(){
    int ans = 0;
    for(int i = 1; i <=n ; i++)
        ans+= degree[i] == 1;
    return ans;
}

int solve(){

    cin >> n >> m;

    int u, v;
    while(m--){
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        degree[u]++; degree[v]++;
    }

    int ans = 0;
    while( check() >= 1 ){

        vector<int> group;
        for(int i=1; i <=n ; i++)
             if(degree[i] == 1)
                group.push_back(i), degree[i] = 0;

        for(int i=0; i<group.size(); i++)
            for(int j=1; j <=n; j++ )
                if(g[group[i]][j])
                    degree[j]--, g[j][group[i]] = 0;
        ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
