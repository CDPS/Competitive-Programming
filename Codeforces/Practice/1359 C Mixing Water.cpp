#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c, h, t;

ll f(ll n){
    return (h*n)+(c*(n-1));
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >>T;

    while(T--){

        cin >> h >> c >> t;

        if(t >= h){
            cout << 1 << "\n";
            continue;
        }

        if(t * 2 <= h+c ){
            cout << 2 << "\n";
            continue;
        }

        ll lo = 2, hi = 1000000, m;
        while(lo < hi){
            m = lo + (hi - lo)/2;
            if(f(m) <= t*((2*m)-1) )
                hi = m;
            else
                lo= m+1;
        }

        ll n1 = lo, n0 = lo-1;
        ll err0 = llabs(f(n0) - t*(2*n0 - 1));
        ll err1 = llabs(f(n1) - t*(2*n1 - 1));

        bool choose_n0 = err0 * (2*n1 - 1) <= err1 * (2*n0 - 1);
        ll best_n = choose_n0 ? n0 : n1;

        ll k = (best_n == 1 ? 1 : 2*best_n - 1);
        cout << k << "\n";
    }

    return 0;
}

