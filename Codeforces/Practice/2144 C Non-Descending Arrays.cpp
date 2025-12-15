#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m = 998244353;

int t, n;
int a[101], b[101];
ll dp[101][2];

ll solve(){

    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = 0;

    dp[1][0] = dp[1][1] = 1;
    for(int i=2;i<=n;i++){
        if(a[i] >= a[i-1] && b[i] >=b[i-1])
            dp[i][0]= (dp[i][0] + dp[i-1][0])%m;
        if(b[i] >= a[i-1] && a[i] >=b[i-1])
            dp[i][1]= (dp[i][1] + dp[i-1][0])%m;
        if(a[i] >= b[i-1] && b[i] >=a[i-1])
            dp[i][0]= (dp[i][0] + dp[i-1][1])%m;
        if(b[i] >= b[i-1] && a[i] >= a[i-1])
            dp[i][1]= (dp[i][1] + dp[i-1][1])%m;
    }

    return (dp[n][0] + dp[n][1])%m;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
