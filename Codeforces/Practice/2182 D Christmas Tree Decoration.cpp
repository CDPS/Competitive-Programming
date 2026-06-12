#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll MOD = 998244353;
ll a[51];

ll fact(int n) {
    ll ans = 1;
    for (int i = 2; i <= n; i++)
        ans = (ans * i) % MOD;
    return ans;
}

ll perm(int n, int k) {
    if (k < 0 || k > n) return 0;
    ll ans = 1;
    for (int i = 0; i < k; i++)
        ans = (ans * (n - i)) % MOD;
    return ans;
}

ll solve(){

    cin >> n;

    ll sum = 0;
    for(int i=0;i<=n;i++)
        cin >> a[i], sum+= a[i];

    ll k = sum/n;

    int r = sum%n;
    int allowed = n-r, curr = 0;
    for(int i=1; i<=n ; i++){
        if(a[i] > k + 1) return 0;
        if(a[i] <= k ) curr++;
    }

    if(curr < allowed ) return 0;

    return ( fact(r) * perm(curr, allowed) )%MOD;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
