#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll p, q;

bool solve(){

    cin >> p >> q;

    return 2*q <= 3*p && p < q;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "Bob" : "Alice") << "\n";

    return 0;
}
