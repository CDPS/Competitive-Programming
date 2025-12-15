#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

ll   a[200001];
ll pfx[200001];
ll sfx[200002];

void solve(){

    cin >> n >> k;

    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        pfx[i] = a[i] + pfx[i-1];
        sfx[n-i+1] = a[n-i+1] + sfx[n-i+2];
    }

    vector<pair<ll, int> > maxsfx( n + 2, {0,0});
    for(int i=n-k+1;i>=1;i--){
        ll curr = sfx[i] - sfx[i+k];
        if( maxsfx[i+1].first > curr )
            maxsfx[i].first = maxsfx[i+1].first, maxsfx[i].second = maxsfx[i+1].second;
        else
            maxsfx[i].first = curr, maxsfx[i].second = i;
    }

    ll maxi = 0;
    int l , r;

    for(int i=k;i<=n-k;i++){

        ll currp = pfx[i] - pfx[i-k];
        ll currs = maxsfx[i+1].first;

        if(currp + currs > maxi )
            l = (i-k)+1, r = maxsfx[i+1].second, maxi = currp + currs;
    }

    cout << l << " " << r << "\n";
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
