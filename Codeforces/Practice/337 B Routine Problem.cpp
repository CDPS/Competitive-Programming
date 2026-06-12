#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

void solve(){

    cin >> a >> b >> c >> d;

    int area1 = a * d, area2 = b * c;

    int p = 0, q = 1;
    if (area1 > area2) {
        p = area1 - area2;
        q = area1;
    } else {
        p = area2 - area1;
        q = area2;
    }

    int div = __gcd(p, q);

    cout << p / div << "/" << q / div << "\n";
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
