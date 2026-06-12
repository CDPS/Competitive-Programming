#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = 1e18;
int t = 1, n;

ll  w[100000];
ll dp[100000][2];

string s[100000][2];

ll solve(){

    cin >> n;
    for(int i=0; i < n; i++ )
        cin >> w[i], dp[i][0] = dp[i][1] = oo;

    for(int i = 0; i < n; i++) {
        cin >> s[i][0]; s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }

    dp[0][0] = 0; dp[0][1] = w[0];
    for(int i = 1; i < n; i++){
        if(s[i][0] >= s[i-1][0] )
            dp[i][0] = min( dp[i][0], dp[i-1][0] );
        if(s[i][0] >= s[i-1][1] )
            dp[i][0] = min( dp[i][0], dp[i-1][1]);
        if(s[i][1] >= s[i-1][0] )
            dp[i][1] = min( dp[i][1], dp[i-1][0] + w[i]);
        if(s[i][1] >= s[i-1][1] )
            dp[i][1] = min( dp[i][1], dp[i-1][1] + w[i]);
    }

    ll ans = min(dp[n-1][0], dp[n-1][1]);

    return ans == oo? -1 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
