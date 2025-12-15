#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k;
string s;

ll solve(){

    cin >> k >> s;

    int n = s.size();

    vector<int> pfx(n +2, 0);
    for(int i= 1; i<=n;i ++)
        pfx[i] = (s[i-1]=='1') + pfx[i-1];

    ll ans = 0;
    map<ll, ll> mp;
    mp[0] = 1ll;
    for(int i=1;i<=n;i++){
        ans+= mp[ pfx[i]-k  ];
        mp[pfx[i]]++;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << "\n";
    return 0;
}
