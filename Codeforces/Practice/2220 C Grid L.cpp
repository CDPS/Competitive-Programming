#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p, q;
void solve(){

    cin >> p >> q;

    ll S = (4*q) + (2*p) + 1;

    ll A = 0, B=0;

    for(ll f  = 3; f*f <= S; f+=2){
        if(S%f==0){
            A = f;
            B = S/f;

            ll n = (A - 1) / 2;
            ll m = (B - 1) / 2;
            if (n > 0 && m > 0 && q <= n * (m + 1) && q <= m * (n + 1)) {
                cout << n << " " << m << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}


int t;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
