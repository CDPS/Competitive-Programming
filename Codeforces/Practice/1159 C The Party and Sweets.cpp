#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll b[100000], g[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll n, m;

    cin >> n >> m;

    ll sg = 0, sb = 0;
    for(ll i=0;i<n;i++) cin >> b[i], sb+= b[i];
    for(ll i=0;i<m;i++) cin >> g[i], sg+= g[i];

    sort(b, b + n);
    sort(g, g + m);

    if(b[n-1] > g[0]) {
        cout << -1 << "\n";
        return 0;
    }

    cout << (sb*m) + sg - ( b[n-1] == g[0]?  b[n-1]*m : (b[n-1]*(m-1)) + b[n-2])  << "\n";
    return 0;
}
