#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int n, x;
    cin >> n;

    map<int, ll> mp;
    int i = 1;
    while(n--)
        cin >> x, mp[i-x]+=x, i++;

    ll ans  = 0;
    for(auto it= mp.begin();it!=mp.end();it++)
        ans = max(ans, it->second);

    cout << ans << "\n";

    return 0;
}
