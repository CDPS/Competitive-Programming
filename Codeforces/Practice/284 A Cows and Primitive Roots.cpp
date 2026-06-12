#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1;

ll eb (ll a, ll b, ll mod){

    ll res=1, x= a%mod;
    while(b>0){
        if(b%2)
            res= (res*x)%mod;
        x = (x*x)%mod;
        b/=2;
    }
    return res;
}


ll f(ll x, ll e, ll mod ){
    return (eb(x, e, mod) - 1 + mod) % mod;
}

ll p;
int solve(){

    cin >> p;

    int ans = 0;
    for( ll  x = 1; x< p; x++){
        int acc= 0;
        for(ll e=1; e<=p-2; e++)
            acc+= f(x, e, p) != 0;
        if(acc == p-2 && f(x, p-1,p) == 0)
            ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
