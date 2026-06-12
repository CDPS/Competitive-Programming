#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m, l, r;

void solve(){

    cin >> n >> m;

    vector<ll> a(n+1), b(n+1),  pfx(n + 1);;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    pfx[n] = max(a[n], b[n]);
    for(int i=n-1; i>=1;i--)
        pfx[i] = max({a[i], b[i], pfx[i+1]});

    for(int i=1;i<=n;i++)
        pfx[i]+=pfx[i-1];

    while(m--){
        cin >> l >> r;
        cout << pfx[r] - pfx[l-1] << " \n"[m==0];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
