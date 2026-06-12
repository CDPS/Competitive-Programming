#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int t, n, x;

void solve(){

    cin >> n;

    vector<int> dp(n + 1, oo);

    for(int i=0;i<n;i++)
        cin >> x, dp[x] = 1;

    for(int i=1;i<=n;i++)
        for(int j = i; j <=n; j+= i)
            dp[j] = min(dp[j], dp[i] + dp[j/i] );

    for(int i=1; i<=n; i++)
        cout << (dp[i]==oo? -1 : dp[i] ) << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
