#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<char,pair<ll,ll>> mp = {{'U',{0,1}},{'D',{0,-1}},{'L',{-1,0}},{'R',{1,0}}};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll xi, yi, xt, yt, n, vx, vy;
    string s;
    cin >> xi >> yi >> xt >> yt >> n >> s;

    vector<pair<ll ,ll>> v; v.push_back({0, 0});
    for(ll i=0;i<n;i++){
        vx = v.back().first  + mp[s[i]].first;
        vy = v.back().second + mp[s[i]].second;
        v.push_back({vx,vy});
    }

    ll l = 0 , h = 2e18, m;

    while(l< h){
        m = l + ( (h-l)/2 );

        vx = ((m/n) * v[n].first) + v[(m%n)].first  + xi;
        vy = ((m/n) * v[n].second)+ v[(m%n)].second + yi;

        ll dist = abs(xt-vx) + abs(yt-vy);
        if( m >= dist)
             h = m;
        else l = m +1;
    }

    cout << (l == 2e18? -1 : l) << "\n";
    return 0;
}
