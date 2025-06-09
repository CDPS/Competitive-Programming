#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll n){
    return (n*(n+1))/2ll;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    ll n, k;

    cin >> t;

    while(t--){

        cin >> n >> k;

        ll l = 0, h = 100000, m;
        while(l< h){
            m = l + ( (h-l)/2 );
            if( f(m) >= k)
                 h = m;
            else l = m +1;
        }

        for(int i=n-1;i>=0;i--){
            if(i== l )  cout << 'b';
            else if(f(l)==k && i==l-1)cout << 'b';
            else if(i==l-( f(l)-k + 1)) cout << 'b';
            else cout << 'a';
        }

        cout << "\n";
    }
    return 0;
}
