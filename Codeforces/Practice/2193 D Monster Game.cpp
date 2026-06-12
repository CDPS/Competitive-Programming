#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll solve(){

    cin >> n;

    vector<ll> a(n+1), pfx(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
        cin >> pfx[i], pfx[i]+=pfx[i-1];

    sort(a.begin(), a.end());

    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll curr = n-i+1;
        auto it = upper_bound(pfx.begin(), pfx.end(), curr);
        int amount = (it - pfx.begin()) - 1;
        ans = max(ans, 1ll*amount*a[i]) ;
    }

    return ans;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
