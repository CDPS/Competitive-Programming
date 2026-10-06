#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

ll n, m, r, c;
ll mod = 998244353;

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

ll solve(){

    cin >> n >> m >> r >> c;
    
    ll free = (n*m) - (  (n-r + 1)*(m-c + 1) );

    return eb(2, free);
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}