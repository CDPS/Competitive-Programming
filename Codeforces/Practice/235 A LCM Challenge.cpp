#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}

int n;

ll solve(){

    cin >> n;

    if(n < 2) return n;

    ll limit = max(1, n - 50), ans = 0;
    for(ll i = n; i >= limit; i--)
        for(ll j = n; j >= limit; j--)
            for(ll k = n; k >= limit; k--)
                ans = max(ans, lcm(i, lcm(j, k)));

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
