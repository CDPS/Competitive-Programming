#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> node;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll t, n, k,x;
    cin >> t;

    while(t--){

        cin >> n >> k;
        map<ll,ll> mp;
        priority_queue<node, vector<node> , greater<node> > pq;
        for(ll i=0;i<n;i++){
            cin >> x;
            ll mod = (k - x % k) % k;
            if(mod == 0 && mp[mod] == 0) continue;
            mp[mod]++;
            pq.push({mp[mod], mod});
        }

        if(mp[0] == n){
            cout << 0 << "\n";
            continue;
        }

        ll ans = 0, current = 0, level = 1;
        while(!pq.empty()){

            node u = pq.top(); pq.pop();
            if(level < u.first)
                ans += k-current, level = u.first, current = 0;
            if(current == u.second)
                ans++, current++;
            else if(current < u.second)
                ans+= (u.second-current) +1, current = u.second + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
