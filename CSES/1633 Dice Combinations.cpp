#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
int dp[1000001];

int main(){

    int n;
    cin >> n;
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + (dp[i - j])) % mod;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
