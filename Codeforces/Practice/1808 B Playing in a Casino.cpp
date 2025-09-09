#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

ll solve(){

    cin >> m >> n;

    vector< vector<ll> > v(n, vector<ll>(m));

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> v[j][i];

    for(int i=0;i<n;i++)
        sort(v[i].begin(), v[i].end());

    ll ans =0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans+= 1ll*v[i][j]*j, ans-= 1ll*(m-1-j)*v[i][j];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}

