#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll m;

int solve(){

    cin >> n >> m;

    vector<pair<int,int>> a(n);

    for(int i=0; i < n; i++) cin >> a[i].first;
    for(int i=0; i < n; i++) cin >> a[i].second;

    vector<ll> pfx_1, pfx_2;
    for(int i=0; i < n; i++){
         if(a[i].second == 1)
            pfx_1.push_back(a[i].first);
         else
            pfx_2.push_back(a[i].first);
    }

    sort(pfx_1.begin(), pfx_1.end(), greater<int>());
    sort(pfx_2.begin(), pfx_2.end(), greater<int>());

    for(int i=1; i < pfx_1.size(); i++)
        pfx_1[i] += pfx_1[i-1];

    int ans = 1e9; ll sum = 0;

    auto it = lower_bound(pfx_1.begin(), pfx_1.end(), m);
    if (it != pfx_1.end()) {
        int index = it - pfx_1.begin();
        ans = min(ans, index + 1 );
    }

    for(int i =0; i<pfx_2.size(); i++){
        sum+= pfx_2[i];
        if( sum >= m){
            ans = min(ans, (i+1)*2 );
            break;
        }
        ll target = m - sum;
        auto it = lower_bound(pfx_1.begin(), pfx_1.end(), target);
        if (it != pfx_1.end()) {
            int index = it - pfx_1.begin();
            ans = min(ans, index + 1 + ((i+1)*2)  );
        }
    }

    return ans == 1e9? -1 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
