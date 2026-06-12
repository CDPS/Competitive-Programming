#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

void solve(){

    cin >> n >> m;

    if(n == 0 && m == 0){
        cout << 0 << " " << 0 << "\n";
        return;
    }

    if(n == 0 && m > 0){
        cout << "Impossible" << "\n";
        return;
    }

    cout << n + max(0, m-n ) << " " << n + max(0, m - 1) << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
