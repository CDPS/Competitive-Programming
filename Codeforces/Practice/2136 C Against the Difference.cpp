#include <bits/stdc++.h>

using namespace std;

int n, t;
int  a[200001];
int dp[200001];
queue<int> mp[200001];

int solve(){

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >>  a[i], mp[i] = queue<int>(), dp[i] = 0;

    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        mp[a[i]].push(i);
        if(mp[a[i]].size() > a[i] ) mp[a[i]].pop();
        if(mp[a[i]].size() == a[i] )
            dp[i] = max(dp[i],  dp[  mp[a[i]].front()-1 ]  + a[i] );
    }

    return dp[n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
