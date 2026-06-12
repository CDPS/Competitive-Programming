#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(){

    cin >> n >> m;

    cout << m + n - 1 << "\n";
    for(int i=1;i<=m;i++)
        cout << 1 << " " << i << "\n";
    for(int i=2;i<=n;i++)
        cout << i << " " << 1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
