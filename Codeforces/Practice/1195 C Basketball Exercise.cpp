#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll  a[100001][2];
ll dp[100001][2];

ll solve(int i, int r){
   if(i==n) return 0;
   if(dp[i][r] != -1) return dp[i][r];
   return dp[i][r] = max( a[i][!r] + solve(i+1, !r), solve(i+1, r));
}

int main(){

    cin >> n;

    for(int j=0;j<2;j++)
        for(int i=1;i<=n;i++)
            cin >> a[i][j], dp[i][j]= 0;

    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            dp[i][j] = max(  a[i][j] + dp[i-1][!j], dp[i-1][j] );

    cout << max( dp[n][0], dp[n][1] ) << "\n";

    return 0;
}
