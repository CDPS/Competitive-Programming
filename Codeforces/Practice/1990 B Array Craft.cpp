#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;

int a[100001];

void solve(){

    cin >> n >> x >> y;

    for(int i=y;i<=x;i++) a[i] = 1;

    for(int i=y-1, mux = 1;i>=1;i--, mux = !mux)
        a[i] = mux? -1: 1;
    for(int i=x+1, mux = 1;i<=n;i++, mux = !mux)
        a[i] = mux? -1: 1;
    for(int i=1;i<=n;i++)
        cout << a[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
