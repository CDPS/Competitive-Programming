#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll pfx[500002];

ll solve(){

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> pfx[i], pfx[i]+= pfx[i-1];

    if(pfx[n]%3 !=0 )
        return 0;

    ll t = pfx[n]/3;

    map<ll, int> mp;

    ll ans = 0;
    for(int i =1; i<=n-1; i++){

        if( pfx[n] - pfx[i] == t )
            ans+= mp[  pfx[i] - t ];

        mp[pfx[i]]++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}


