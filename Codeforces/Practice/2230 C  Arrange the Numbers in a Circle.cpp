#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int t, n, x;

ll solve(){

    cin >> n;

    ll count_1 = 0;

    vector<ll> v;
    for(int i=0; i < n; i++){
        cin >> x;
        if(x == 1) count_1++;
        else v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<int>());

    ll ans = 0;

    if(v.size() == 1){
        ans = v[0] + min(count_1, v[0] / 2);
    }else{
        
        for(int i= 0; i < v.size(); i++){
            ans+= v[i];
            ans+=  min(count_1, (v[i]/2)-1); 
            count_1 -= min(count_1, (v[i]/2)-1); 
        }
    }

    return ans <= 2? 0 : ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
       cout <<  solve() << "\n";
    
    return 0;
}