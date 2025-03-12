#include <bits/stdc++.h>

using namespace std;

int oo = 2e9;
int w[1001],  p[1001];
int dp[1001][100001];
int n , x;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> n >> x;

    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<=n;i++) cin >> p[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=x;j++)
            dp[i][j] = max( j-w[i]>=0 ? p[i] + dp[i-1][j-w[i]] : -oo, dp[i-1][j]);

    cout << dp[n][x] << "\n";

    return 0;
}
