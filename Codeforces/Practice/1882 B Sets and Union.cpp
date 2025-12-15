#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m, x;

int solve(){

    cin >> n;

    set<int> all;
    vector< vector<int> > g(n);

    for(int i=0;i<n;i++){
        cin >> m;
        while(m--)
            cin >> x, all.insert(x), g[i].push_back(x);
    }

    map<int,int> mp;
    int index = 0;
    for(auto it=all.begin(); it!=all.end();it++)
        mp[*it] = index++;

    vector<ll> sets;
    for(int i=0;i<n;i++){
        ll mask =0;
        for(int j=0;j<g[i].size();j++)
            mask  |= (1ll <<  mp[g[i][j]] );
        sets.push_back(mask);
    }

    int ans = 0;
    for(int i=0;i<all.size();i++){
        ll curr = 0;
        for(int j=0;j<n;j++)
            if( ( sets[j]&(1ll<<i) ) == 0 )
                curr|= sets[j];

        ans = max(ans, __builtin_popcountll(curr) );
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
