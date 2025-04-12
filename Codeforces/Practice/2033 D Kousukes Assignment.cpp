#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;

    cin >> t;
    while(t--){

        cin >> n;

        long long sum = 0, x;
        map<long long, int> mp; mp[0] = 0;

        memset(dp, 0, sizeof dp);
        for(int i=1;i<=n;i++){
            cin >> x; sum += x;
            dp[i] = dp[i-1];
            if(mp.find(sum)!=mp.end())
                dp[i] = max(dp[i], dp[mp[sum]] + 1 );
            mp[sum] = i;
        }

        int ans =0;
        for(int i=1;i<=n;i++)
            ans = max(ans, dp[i]);

        cout << ans << "\n";
    }
    return 0;
}
