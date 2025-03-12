#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    ll  n;
    cin >> t;

    while(t--){

        cin >> n;

        ll ans = 0;
        for(ll i=0;i<=60 && (1ll<<i)<=n;i++){
            ll groups = (n+1)/(1ll<<(i+1ll));
            ll rest   = (n+1)%(1ll<<(i+1ll));
            ans += groups + (groups-1) + (rest > 0) + ( rest >(1ll<<i));
        }
        cout << ans << "\n";
    }
    return 0;
}
