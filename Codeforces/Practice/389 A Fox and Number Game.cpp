#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x;

int solve(){

    cin >> n;

    int g = 0;
    for(int i=0; i < n; i++)
        cin >> x, g = __gcd(g, x);

    return g * n;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
