#include <bits/stdc++.h>

using namespace std;

int m = 1e9 + 7;
int dp[100000];

int main(){

    int n;
    cin >> n;

    int sum = (n*(n+1))/2;

    if(sum%2){
        cout << 0 << "\n";
        return 0;
    }

    dp[0] = 1;
    for(int i=1;i<=n;i++)
        for(int j= sum/2;j>=i;j--)
            dp[j] = (dp[j] + dp[j-i])%m;

    cout << dp[sum/2] << "\n";

    return 0;
}
