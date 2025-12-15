#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

ll a, b;

ll solve(){

    cin >> a >> b;

    if(a%2 && b%2) return a*b + 1;
    if(a%2==0 && b%2) return -1;

    ll ans = ((b/2)*a ) + 2;

    return (ans%2) ? -1 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
