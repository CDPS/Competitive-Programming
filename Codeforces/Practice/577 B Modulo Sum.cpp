#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[1000000];

bool solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i], a[i]%=m;

    if(n > m) return true;

    vector<bool> dp(m, false);
    for (int i = 0; i < n; i++) {

        vector<bool> next_dp = dp;

        next_dp[a[i]] = true;
        for (int j = 0; j < m; j++)
            next_dp[(j + a[i])%m ] = dp[j]? true : next_dp[(j + a[i])%m ]  ;

        dp = next_dp;
    }

    return dp[0];
}

int main(){

    cout << (solve()? "YES" : "NO") << "\n";
}
