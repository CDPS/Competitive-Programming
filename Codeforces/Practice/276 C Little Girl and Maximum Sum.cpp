#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll    a[200002];
ll    b[200002];
ll  pfx[200002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, q, l, r;

    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];

    while(q--){
        cin >> l >> r;
        pfx[l]++, pfx[r+1]--;
    }

    for(int i=1;i<=n;i++)
        pfx[i]+=pfx[i-1];

    sort(pfx, pfx + n + 1, greater<ll>());
    sort(a,   a+ n + 1, greater<ll>());

    ll ans = 0;
    for(int i=0;i<n;i++)
        ans+= (pfx[i]*a[i]);

    cout << ans << "\n";

    return 0;
}
