#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[200001];

ll solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<ll> pfx(n+2), sfx(n+2);

    pfx[1] = a[1];
    for(int i=2;i<=n;i++)
        pfx[i] = abs(a[i]) + pfx[i-1];

    for(int i=n;i>=1;i--)
        sfx[i] = sfx[i+1] - a[i];

    ll ans = -1e18;
    for(int i = 1;i <=n ; i++)
        ans = max(ans, pfx[i-1] + sfx[i+1] );

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}


