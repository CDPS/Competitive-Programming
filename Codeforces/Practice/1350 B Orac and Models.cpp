#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int  a[100001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=1;i<=n;i++)  dp[i] = 1;

        int ans = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            for(int j=1; j*j<=i;j++){
                if( i%j==0 && a[j] < a[i] )
                    dp[i] = max(dp[i], 1 + dp[j] );
                if( i%j==0 && i/j < i && a[i/j] < a[i] )
                    dp[i] = max(dp[i], 1+ dp[i/j]);
            }
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }
    return 0;
}
