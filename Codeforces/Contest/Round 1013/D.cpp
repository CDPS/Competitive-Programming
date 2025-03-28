#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, m, k;

ll f(ll x){
   return (((m/(x+1))*x) + (m%(x+1)) )*n;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n >> m >> k;

        ll l = 1, h = m, mid;
        while(l< h){
            mid= l + ( (h-l)/2 );
            if( f(mid) >= k)
                 h = mid;
            else l = mid +1;
        }
        cout << l  << "\n";
    }
    return 0;
}
