#include <bits/stdc++.h>

using namespace std;

int t , n,  m;

void solve(){

    cin >> n >> m;

    if(n > m) {
        cout << "NO\n";
        return;
    }
    if(n == 0 && m % 2 == 0) {
        cout << "NO\n";
        return;
    }
    if(n == 0) {
        cout << "YES\n";
        for(int i = 2; i <= n + m; i++)
            cout << 1 << " " << i << "\n";
        return;
    }

    cout << "YES\n";

    int all = n + m;
    int L = all %2? 2*n : 2*n -1;

    for(int i = 2; i <= L; i++)
        cout << i - 1 << " " << i << "\n";

    for(int i = L + 1; i <= n + m; i++)
        cout << L << " " << i << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

