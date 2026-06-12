#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll health, k;
ll a[200001];

ll sum_pfx[200002];
ll min_pfx[200002];
ll max_sfx[200002];

ll f(ll x){

    if (x == 0) return 0;

    ll div = x / (n + k);
    ll mod = min((ll)n, x % (n + k));

    __int128 sum = (__int128)sum_pfx[n] * div + sum_pfx[mod];

    if (mod > 0 && mod < n)
        sum += max(0LL, max_sfx[mod + 1] - min_pfx[mod]);

    if (sum >= health) return health;

    return (ll)sum;
}

ll solve(){

    cin >> n >> health >> k;

    for(int i=1;i<=n;i++)
        cin >> a[i], sum_pfx[i] = a[i] + sum_pfx[i-1];

    min_pfx[0] = 1e9;
    for(int i=1;i<=n;i++)
        min_pfx[i] = min(min_pfx[i-1], a[i]);

    max_sfx[n+1] = -1;
    for(int i=n;i>=1;i--)
         max_sfx[i] = max(max_sfx[i+1], a[i]);

    ll l = 0, h = 1e18, m;
    while(l< h){
        m = l + ( (h-l)/2 );
        if( f(m) >= health)
             h = m;
        else l = m +1;
    }

    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
