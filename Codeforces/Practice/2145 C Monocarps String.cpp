#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int t, n;
string s;

int a[200001];

int solve(){

    cin >> n >> s;

    int pfx_n = 0;
    for(int i=1;i<=n;i++)
        a[i] = (s[i-1]=='a')? 1: -1, pfx_n += a[i];

    map<int, int> mp; mp[0] = 0;

    if(pfx_n == 0) return 0;

    int ans = n , sum = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
        if(mp.count(sum - pfx_n))
            ans = min(ans, i - mp[sum - pfx_n]);
        mp[sum] = i;
    }

    return ans== n ? -1 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
