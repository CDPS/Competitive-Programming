#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n;

void solve(){

    cin >> n;

    vector<ll> ans;

    ans.push_back(n);

    for(int i=0; i <=60;i++){
        if( (n&(1ll << i)) != 0){
            n &= ~(1ll << i);
            if(n > 0)
                ans.push_back(n);
            n |= (1ll << i);
        }
    }

    cout << ans.size() << "\n";
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << " \n"[i==0];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
