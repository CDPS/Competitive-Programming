#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;

vector<int> g[100000];

int parent[100000];
int cant  [100000];
int vs    [100000];

ll total =0;
ll ans[100000];

ll f(int x){
    return (1ll*x*(x+1))/2ll;
}

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){

    int px= findset(x); int py= findset(y);

    if(px==py) return;

    total-= f(cant[px]) + f(cant[py]);

    if(cant[px] < cant[py])
        swap(px, py);

    parent[py] = px;
    cant[px] += cant[py];
    total += f(cant[px]);
}

void solve(){

    int x, y;

    cin >> n; total = 0;
    for(int i=0;i<n;i++)
        cant[i] = 1, parent[i] = i, vs[i] = false, g[i].clear();

    cin >> x;
    for(int i=0;i<n-1;i++){
        cin >> y;
        g[abs(x-y)].push_back(i);
        x = y;
    }

    for(int k = n-1; k>=1; k--){
        for(int idx : g[k]){
            total++;
            vs[idx] = true;
            if(idx>0 && vs[idx - 1])
                unionset(idx-1, idx);
            if (idx < n - 2 && vs[idx + 1])
                unionset(idx, idx + 1);
        }
        ans[k] = total;
    }

    for(int i=1;i<=n-1;i++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

