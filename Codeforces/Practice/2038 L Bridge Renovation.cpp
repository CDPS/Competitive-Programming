#include<bits/stdc++.h>

using namespace std;

int dp[1001];

void precalc(){

    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;
    dp[3] = 4;
    dp[4] = 5;
    dp[5] = 6;
    dp[6] = 7;
    for(int i=7;i<=1000;i++)
        dp[i] = dp[i-6] + 7;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    precalc();

    int n;
    cin >> n;
    cout << dp[n] << "\n";

    return 0;
}
