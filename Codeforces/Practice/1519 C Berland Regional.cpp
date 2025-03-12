#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll u[200000];
ll a[200001];
vector<ll> g[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll t, n, x;

    cin >> t;
    while(t--){

        cin >> n;
        for(int i=0;i<=n;i++)
            a[i] = 0, g[i].clear();

        for(int i=0;i<n;i++) cin >> u[i];

        for(int i=0;i<n;i++){
            cin >> x;
            if(g[u[i]].empty()) g[u[i]].push_back(0);
            g[u[i]].push_back(x);
        }
        for(int i=1;i<=n;i++) sort(g[i].begin(), g[i].end());

        for(int i=1;i<=n;i++)
            for(int j=1;j<g[i].size();j++)
                g[i][j]+=g[i][j-1];

        for(int i=1;i<=n;i++)
            for(int k=1;k<= g[i].size();k++)
                a[k]+= g[i].back() - g[i][(g[i].size()-1)%k];

        for(int i=1; i<=n; i++)
            cout << a[i] << " \n"[i==n];
    }
    return 0;
}
