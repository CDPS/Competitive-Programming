#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ll n, k, x;
    cin >> n >> k;
    map<ll, ll> mp;
    for(ll i=0;i<n;i++)
        cin >> x, mp[x]++;

    ll first, second;
    for(auto it = mp.begin();it!= mp.end();it++){
        if( k <= it->second * n ){first = it->first; break;}
        k-= it->second * n;
    }

    for(auto it = mp.begin();it!= mp.end();it++){
        if( k <= it->second*mp[first]  ){second = it->first; break;}
        k-= it->second*mp[first];
    }

    cout <<  first << " " << second << "\n";
}
