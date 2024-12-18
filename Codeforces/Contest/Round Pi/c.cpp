#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;
ll a[200000], r[200000], l[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    unordered_map<ll,ll> acc;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]%k==0)
            l[i] = acc[ a[i]/k ];
        acc[a[i]]++;
    }

    acc.clear();
    for(ll i=n-1;i>=0;i--){
        if(a[i]%k==0)
            r[i] = acc[ a[i]*k ];
        acc[a[i]]++;
    }

    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(a[i]%k==0)
            ans += l[i] * r[i];
    }

    cout << ans << "\n";

    return 0;
}
