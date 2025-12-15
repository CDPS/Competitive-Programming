#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int    a[200001];
ll dp[2][200001];

ll solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[0][i] = dp[1][i] = 0;
    }

    for(int i=1;i<=n;i++){
        dp[0][i] = max( { dp[0][i-1] + a[i], dp[1][i-1] + a[i], abs( dp[0][i-1] + a[i] ), abs(dp[1][i-1] + a[i] )  } );
        dp[1][i] = min( { dp[0][i-1] + a[i], dp[1][i-1] + a[i], abs( dp[0][i-1] + a[i] ), abs(dp[1][i-1] + a[i] )  } );
    }

    return max(dp[0][n], dp[1][n]);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
