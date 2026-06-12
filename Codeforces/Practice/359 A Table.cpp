#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m, row;

int solve(){

    cin >> n >> m;

    bool check = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> row, check |= (row == 1 && (i == 1 || i == n || j == 1 || j == m) );

    return check? 2 : 4;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

