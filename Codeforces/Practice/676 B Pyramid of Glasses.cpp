#include <bits/stdc++.h>

using namespace std;

int tt = 1, n , t ;

double dp[15][15];

int solve() {

    cin >> n >> t;

    dp[0][0] = t;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c <= r; c++) {
            if (dp[r][c] > 1.0) {
                double overflow = dp[r][c] - 1.0;
                dp[r][c] = 1.0;
                dp[r+1][c] += overflow / 2.0;
                dp[r+1][c+1] += overflow / 2.0;
            }
        }
    }

    int ans = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= r; c++)
            ans += (dp[r][c] >= 1.0);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(tt--)
        cout << solve() << "\n";

    return 0;
}

