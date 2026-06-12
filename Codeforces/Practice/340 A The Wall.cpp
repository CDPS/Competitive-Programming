#include <bits/stdc++.h>

using namespace std;

int t = 1, x, y, a, b;

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / __gcd(a, b)) * b;
}

int solve(){

    cin >> x >> y >> a>> b;

    int k = lcm(x,y);

    return (b/k) - ( (a-1)/k );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
