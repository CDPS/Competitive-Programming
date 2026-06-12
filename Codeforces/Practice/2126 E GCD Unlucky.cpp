#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}

int t, n;
bool solve(){

    cin >> n;

    vector<ll> pfx(n + 2), sfx(n + 2);
    for(int i=1; i<=n; i++) cin >> pfx[i];
    for(int i=1; i<=n; i++) cin >> sfx[i];

    for(int i=2; i <= n; i++)
        if(pfx[i-1] % pfx[i] != 0) return false;
    for(int i=1; i < n; i++)
        if(sfx[i+1] % sfx[i] != 0) return false;

    if(sfx[1] != pfx[n] ) return false;

    for(int i=1; i <= n; i++){
        ll ai = lcm(pfx[i], sfx[i]);
        if (i > 1 && __gcd(pfx[i-1], ai) != pfx[i])
            return false;
        if (i < n && __gcd(sfx[i+1], ai) != sfx[i])
            return false;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}
