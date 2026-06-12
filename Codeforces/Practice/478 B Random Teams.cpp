#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1;
ll n, m;

ll f(ll x){
    return x*(x-1)/2;
}

void solve(){

    cin >> n >> m;

    ll ans1 = f(n/m) * (m - (n%m)) ;
    ll ans2 = f(n/m + (n%m != 0)) * (n%m);

    cout << ans1 + ans2 << " " << f(n-m+1) << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        solve();

    return 0;
}


