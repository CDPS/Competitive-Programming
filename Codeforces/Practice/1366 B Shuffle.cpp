#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll x, ll s){
    ll ans = 0;
    if(x<=s){
        ans = (x*(x+1))/2;
    }
    else{
        ans = (s*(s+1))/2;
        x-= s;
        ll b = s-1-x;
        ans += (s*(s-1))/2 - (b*(b+1))/2;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t; ll k, x;
    cin >> t;

    while(t--){
        cin >> k >> x;

        ll l = 1 , h =2*k-1, m;

        while(l< h){
            m = l + ( (h-l)/2 );
            if( f(m,k) >= x)
                 h = m;
            else l = m +1;
        }
        cout << l << "\n";
    }
    return 0;
}

