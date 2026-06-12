#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll x;

void solve(){

    cin >> n;

    vector<ll> odds, evens;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x%2)
            odds.push_back(x);
        else
            evens.push_back(x);
    }

    sort(odds.begin(),  odds.end(), greater<int>());
    sort(evens.begin(), evens.end(), greater<int>());

    vector<ll> pfx(evens.size() + 1, 0);
    for(int i=0;i<evens.size();i++)
        pfx[i+1] = evens[i] + pfx[i];

    vector<ll> ans(n, 0);
    for(int k=0; k<n; k++){

        if(odds.empty()){
            ans[k] = 0 ;
            continue;
        }

        int acc_odd = 1;
        if (k  > evens.size())
            acc_odd +=  k  - evens.size();
        if(acc_odd % 2 == 0) acc_odd++;

        ans[k] =  (acc_odd > odds.size() || acc_odd > k + 1) ? 0 : odds[0] + pfx[k + 1 - acc_odd ];
    }

    for(int i=0;i  <n ; i ++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
