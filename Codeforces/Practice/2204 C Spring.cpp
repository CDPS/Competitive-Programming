#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll a, b, c, m;

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / __gcd(a, b)) * b;
}

ll f(ll x, ll y, ll z){
    return (x*6) + (y*3) + (z*2);
}

void solve(){

    cin >> a >> b >> c >> m;

    ll count_all    = (m/lcm(lcm(a, b), c)) ;
    ll count_ab     = (m/lcm(a,b)) - count_all;
    ll count_ac     = (m/lcm(a,c)) - count_all;
    ll count_bc     = (m/lcm(b,c)) - count_all;
    ll count_only_a = (m/a) - count_ab - count_ac - count_all;
    ll count_only_b = (m/b) - count_ab - count_bc - count_all;
    ll count_only_c = (m/c) - count_ac - count_bc - count_all;

    cout << f(count_only_a, count_ab + count_ac, count_all) << " ";
    cout << f(count_only_b, count_ab + count_bc, count_all) << " ";
    cout << f(count_only_c, count_ac + count_bc, count_all) << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
