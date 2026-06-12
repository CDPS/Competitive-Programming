#include <bits/stdc++.h>

using namespace std;

int t = 1;
int a1, b1, a2, b2, a3, b3;

bool check(int w1, int h1, int w2, int h2) {

    if (w1 + w2 <= a1 && max(h1, h2) <= b1) return true;
    if (w1 + w2 <= b1 && max(h1, h2) <= a1) return true;

    if (max(w1, w2) <= a1 && h1 + h2 <= b1) return true;
    if (max(w1, w2) <= b1 && h1 + h2 <= a1) return true;

    return false;
}

bool solve() {

    cin >> a1 >> b1 >>  a2 >> b2 >> a3 >> b3;
    return check(a2, b2, a3, b3) ||
           check(b2, a2, a3, b3) ||
           check(a2, b2, b3, a3) ||
           check(b2, a2, b3, a3);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
