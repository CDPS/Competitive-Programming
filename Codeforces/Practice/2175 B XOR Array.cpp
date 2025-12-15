#include <bits/stdc++.h>

using namespace std;

int t, n, l, r;
int p[400001];

void solve() {

    cin >> n >> l >> r;

    p[l - 1] = p[r] = 1;
    for (int i = 0, curr = 2; i <= n; i++)
        if (i != l - 1 && i != r)
            p[i] = curr++;

    for (int i = 1; i <= n; i++)
        cout <<  (p[i] ^ p[i - 1]) << " \n"[i==n];
}

int main() {

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
