#include <bits/stdc++.h>

using namespace std;

int n;
int a[101];
int dp[101][3];
int oo = 1e9;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> a[i], dp[i][0] = dp[i][1] = dp[i][2] = oo;

    for(int i=1;i<=n;i++){
        dp[i][0] = 1 +  min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if(a[i]== 1 || a[i]== 3 )
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        if(a[i]== 2 || a[i]== 3)
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]})<< "\n";

    return 0;
}

