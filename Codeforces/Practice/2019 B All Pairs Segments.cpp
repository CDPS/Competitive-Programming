#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, q;

ll  a[100001];
ll dp[100001];

void solve(){

    cin >> n >> q;

    for(int i=1;i<=n;i++)
        cin >> a[i];

    map<ll, ll> mp;

    dp[1] = n - 1;
    mp[n-1]++;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + n - 2*i + 2 ;
        mp[dp[i]]++;
        mp[dp[i-1] - (i-2) ] += a[i]-a[i-1] -1;
    }

    ll x;
    for(int i=0;i<q;i++)
        cin >> x, cout << mp[x] << " \n"[i==q-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        solve();

    return 0;
}
