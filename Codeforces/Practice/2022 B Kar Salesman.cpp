#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, k;
ll x;

ll solve(){

    cin >> n >> k;

    ll maxi = -1e18, sum =0;
    for(int i=0;i<n; i++ )
        cin >> x, maxi = max(maxi, x), sum += x;

    ll dist = ceil((double)sum/(double)k);

    return  max(maxi, dist);
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}
