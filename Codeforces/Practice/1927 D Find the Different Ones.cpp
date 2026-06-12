#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m, l, r;

int  a[200001];
int dp[200001];

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    dp[0] = 0;
    for(int i=1; i<=n;i++)
        dp[i] = (a[i] == a[i-1])? dp[i-1] : i-1;

    cin >> m;
    while(m--){
        cin >> l >> r;
        if(dp[r] < l )
            cout << -1 << " " << -1 << "\n";
        else
            cout << dp[r] << " " << r << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}


