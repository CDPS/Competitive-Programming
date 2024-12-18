#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll oo = 1000000000;

ll t, k, l1, r1, l2, r2;

ll getMin(ll x){
    ll l = l1, h = r1+1, m;
    if(l*x > r2 ) return 0;
    while(l< h){
        m = l + ( (h-l)/2 );
        if(x * m > r2)
            h = m;
        else if(x * m >= l2 && x*m <= r2)
            h = m;
        else
            l = m +1;
    }
    return l;
}

ll getMax(ll x){
    ll l = l1-1, h = r1, m;
    if(l*x > r2 ) return 0;
    while(l< h){
        m = l + ( (h-l+1)/2 );
        if(x * m < l2)
            l = m;
        else if( x * m >= l2 && x*m <= r2)
			l = m;
		else
			h = m - 1;
    }
    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--){

        cin >> k >> l1 >>  r1 >>  l2 >>  r2;

        ll ans = 0;
        for(ll x = 1; x <= oo; x*=k){
            ll minimum = getMin(x);
            ll maximum = getMax(x);
            if(minimum == 0 || maximum ==0) break;
            ans += maximum - minimum + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}


