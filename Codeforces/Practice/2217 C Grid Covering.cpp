#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n , m, a, b;

bool solve(){
    cin >> n >> m >> a >> b;
    return __gcd(a, n) == 1 &&  __gcd(b, m) == 1 && __gcd(n, m) <= 2;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
