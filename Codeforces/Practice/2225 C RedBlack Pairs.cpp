#include <bits/stdc++.h>

using namespace std;

int t, n;

char a[2][200001];

int solve(){

    cin >> n;
    for(int i=0; i < 2; i++)
        for(int j=1; j <= n; j++)
            cin >> a[i][j];

    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;
    dp[1] = a[0][1] != a[1][1];
    for(int i=2; i <= n; i++)
        dp[i] = min(dp[i-2] + (a[0][i-1] != a[0][i]) + (a[1][i-1] != a[1][i]) , dp[i-1] + (a[0][i] != a[1][i]) );

    return dp[n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
