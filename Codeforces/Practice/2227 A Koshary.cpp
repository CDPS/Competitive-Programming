#include <bits/stdc++.h>

using namespace std;

int t, x, y;

bool solve(){

    cin >> x >> y;

    return !(x%2 && y%2);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
