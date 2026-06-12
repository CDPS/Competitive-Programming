#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x;

void solve(){

    cin >> n >> x;

    if(x == 10 && n == 1) {
        cout << -1 << "\n";
        return;
    }

    if(x == 10 )
        cout << 10;

    for(int i=0; i < n - 2*(x==10); i++)
        cout << (x == 10? 0 : x);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
