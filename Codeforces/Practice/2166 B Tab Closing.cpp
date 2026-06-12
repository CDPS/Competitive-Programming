#include <bits/stdc++.h>

using namespace std;

int t, n, a, b;

int solve(){

    cin >> a >> b >> n;

    if(1ll* b *n <= a || b == a) return 1;

    return 2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

