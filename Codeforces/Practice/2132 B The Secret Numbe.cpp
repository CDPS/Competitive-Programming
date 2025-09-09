#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n;

vector<ll> solve(){
    cin >> n;
    ll pow = 1e17;
    vector<ll> ans;
    for(int i=1;i<=17;i++, pow/=10){
        if(n%(pow+1)==0)
            ans.push_back(n/(pow+1));
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){
       auto ans = solve();

       cout << ans.size()<< "\n";
       for(int i=0;i<ans.size();i++)
            cout << ans[i] << " \n"[i==ans.size()-1];
    }
    return 0;
}
