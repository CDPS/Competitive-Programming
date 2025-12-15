#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll solve(){

    cin >> n;

    vector<vector<ll>>  pfx(2, vector<ll> (n+1, 0 ));

    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)
            cin >> pfx[i][j], pfx[i][j]+=pfx[i][j-1];

    ll ans = 1e18;
    for(int i=1;i<=n;i++)
        ans  = min(max(pfx[0][n]-pfx[0][i],pfx[1][i-1]), ans );

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
