#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, k, n, a, b;

bool f(ll x){
    return k-(a*x)-(b*(n-x)) >= 1ll;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> k >> n >> a >> b;
        ll l = 0, h = n, m;
        while(h-l>1){
            m = l + ( (h-l)/2 );
            if( f(m) )
                 l = m;
            else h = m -1;
        }

        ll ans;
        if(f(h)) ans = h;
        else if(f(l)) ans = l;
        else ans = -1;

        cout << ans << "\n";
    }
    return 0;
}
