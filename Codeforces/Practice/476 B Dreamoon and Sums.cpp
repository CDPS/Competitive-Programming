#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll a, b;

ll solve(){

    cin >> a >> b;

    ll sum_b = (b*(b-1))/2;
    ll sum_a = (a*(a+1))/2;

    sum_a = ( (sum_a%mod)*b )%mod;
    sum_a = ( (sum_a) + a )%mod;

    return ( (sum_a%mod)*(sum_b%mod) )%mod;
}

int t = 1;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
