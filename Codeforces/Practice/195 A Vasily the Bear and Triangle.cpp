#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> x >> y;

    int d = abs(x) + abs(y);

    int signX = (x > 0) ? 1 : -1;
    int signY = (y > 0) ? 1 : -1;

    if (x < 0)
        cout << -d << " " << 0 << " " << 0 << " " << signY * d << "\n";
     else
        cout << 0 << " " <<  signY * d << " " << d << " " << 0 << "\n";

    return 0;
}
