#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll t,n,k,x;
    cin >> t;

    while(t--){

        cin >> n >> k;

        vector<ll> v;
        for(int i=0;i<n;i++)
            cin >> x, v.push_back(x);

        ll ans = 0;
        if(k <= 2){

            sort(v.begin(), v.end());

            ans = 2e18;
            for(int i=0;i<n-1;i++)
                ans = min(ans,min(v[i],v[i+1]-v[i]));
            ans = min(ans, v[n-1]);
            k--;

            if(k){
                for(int i=0;i<v.size();i++){
                    for(int j=i+1;j<v.size();j++){
                        ll x = v[j] - v[i];
                        ll p = lower_bound(begin(v), end(v), x) - begin(v);
                        if (p < n) ans = min(ans, v[p] - x);
                        if (p > 0) ans = min(ans, x - v[p - 1]);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
