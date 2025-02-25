#include <bits/stdc++.h>

using namespace std;

int const m = 1e9 + 7;

int dp[2001][2001];

int main(){

    int n, l;

    cin >> n >> l;

    for(int i=0;i<=n;i++) dp[1][i] = 1;

    for(int i=2;i<=l;i++){
        for(int j=1;j<=n;j++){
            for(int k=1; k*k<=j;k++){
                if(j%k==0){
                    dp[i][j] = (dp[i][j] + dp[i-1][k])%m;
                    if(k != j/k)
                        dp[i][j] = (dp[i][j] + dp[i-1][j/k])%m;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = (ans + dp[l][i])%m;

    cout << ans  << "\n";
    return 0;
}
