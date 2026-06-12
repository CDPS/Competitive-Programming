#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;
int  w[50001][6];
int dp[50001][6];

void solve(){

    cin >> n  >> m;
    for(int i=1;i <=n; i++)
        for(int j= 1; j <=m;j++)
            cin >> w[i][j];

    for(int i=1; i <=n; i++)
        for(int j = 1; j<=m; j++ )
            dp[i][j] = max( dp[i-1][j], dp[i][j-1]) + w[i][j];

    for(int i=1;i<=n; i++)
        cout << dp[i][m] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
