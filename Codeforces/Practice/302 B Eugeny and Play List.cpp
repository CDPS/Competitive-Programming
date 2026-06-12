#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, x, y, n, m;

void solve(){

    cin >> n >> m;

    vector<ll> pfx(n+1);
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        pfx[i] = 1ll*x*y; pfx[i] += pfx[i-1];
    }

    while(m--){
        cin >> x;
        auto it = lower_bound(pfx.begin(), pfx.end(), x);
        cout << (it-pfx.begin())<< "\n" ;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
