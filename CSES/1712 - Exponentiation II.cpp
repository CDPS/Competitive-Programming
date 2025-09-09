#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m = 1e9 + 7;

ll eb(ll a,ll b, ll mod){
    ll res=1, x= a%mod;
    while(b>0){
        if(b%2)
            res= (res*x)%mod;
        x = (x*x)%mod;
        b/=2;
    }
    return res;
}

ll solve(ll a, ll b, ll c ){
    ll e = eb(b % (m-1), c, m-1);
    return eb(a, e, m);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    ll a, b, c;
    cin >> t;

    while(t--){
        cin >> a >> b >> c;
        cout << solve(a,b,c) << "\n";
    }
    return 0;
}

