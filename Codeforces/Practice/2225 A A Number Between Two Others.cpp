#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll x, y;

bool solve(){

    cin >> x >> y;
    return (y-x)/x > 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
