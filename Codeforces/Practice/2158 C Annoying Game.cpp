#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = -1e18;
int t, n, k;

ll a[200001];
ll b[200001];

ll solve(){

    cin >> n >> k;

    for(int i=1; i <=n; i++) cin >> a[i];
    for(int i=1; i <=n; i++) cin >> b[i];

    vector<ll> pfx (n + 2,oo), sfx (n + 2,oo);
    for(int i=1, j = n ;i<=n; i++, j--){
        pfx[i] = max(a[i], pfx[i-1] + a[i]);
        sfx[j] = max(a[j], sfx[j+1] + a[j]);
    }

    ll ans = oo;
    for(int i=1;i<=n;i++){
        if(k%2==0)
            ans = max(ans, pfx[i]);
        else
            ans = max(ans, pfx[i] + sfx[i] - a[i] + b[i]);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
