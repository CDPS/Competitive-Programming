#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[300001];

int  solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(7, 1e9));

    dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = dp[0][6] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1; j<=6; j++)
            for(int k=1;k<=6;k++)
                if(k != j && k != 7-j)
                    dp[i][j] = min(dp[i][j], (j!=a[i]) + dp[i-1][k]);

    int ans = 1e9;
    for(int i=1;i<=6;i++)
        ans = min(ans, dp[n][i]);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
