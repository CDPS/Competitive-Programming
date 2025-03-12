#include <bits/stdc++.h>

using namespace std;

int const m = 1e9 + 7;

int a[100000];
int dp[100000][101];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    if(a[0]==0){
        for(int i=1;i<=k;i++)
            dp[0][i] = 1;
    }
    dp[0][a[0]] = 1;

    for(int i=1;i<n;i++){
        int init = a[i]==0? 1 : a[i];
        int last = a[i]==0? k : a[i];
        for(int j= init; j<=last;j++)
            for(int l=-1; l<=1;l++)
                if(j+l>=1 && j+l<=k)
                    dp[i][j]= (dp[i][j] + dp[i-1][j+l])%m;
    }

    int ans = 0;
    for(int i= 1; i<=k;i++)
        ans= (ans + dp[n-1][i])%m;

    cout << ans << "\n";
    return 0;
}
