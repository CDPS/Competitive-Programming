#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int  a[100001];
int dp[100001];

int solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    dp[n] = a[n];
    for(int i=n-1;i>=1;i--)
        dp[i] = max(a[i], dp[i+1] + 1);

    return dp[1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
