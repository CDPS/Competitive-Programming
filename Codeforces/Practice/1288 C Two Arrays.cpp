#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[21][1001];
int t = 1, n, m;

int solve(){

    cin >> n >> m;

    dp[0][0] = 1;
    for(int i = 1;i <= 2*m; i++)
        for(int j = 1; j <=n; j++)
            for(int k= 0; k<=j; k++)
                dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;

    int ans = 0;
    for(int j = 1; j <= n; j++)
        ans = (ans + dp[2*m][j]) % mod;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n";

    return 0;
}
