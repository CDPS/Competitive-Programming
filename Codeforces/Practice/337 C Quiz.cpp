#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 9;

ll eb (ll a, ll b){

    ll res=1, x= a%mod;
    while(b>0){
        if(b%2)
            res= (res*x)%mod;
        x = (x*x)%mod;
        b/=2;
    }
    return res;
}

ll n , m, k;

ll f(ll x){
    ll pow = (eb(2, x) - 1 + mod) % mod;
    ll mul = (2 * k) % mod;
    return (mul * pow) % mod;
}

ll solve(){

    cin >> n >> m >> k;

    ll init = (n-m)*(k-1);
    ll remain = max(0ll, m - init );
    return ( ((m - remain)%mod)  + f(remain/k) + (remain%k)%mod )%mod ;
}

int t = 1;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
