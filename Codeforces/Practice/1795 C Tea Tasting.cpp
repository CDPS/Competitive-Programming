#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[200001];
ll b[200001];
ll pfx[200001];

void solve(){

    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        cin >> b[i], pfx[i] = b[i] + pfx[i-1];

    vector<ll> table (n  + 2);
    vector<ll> remain(n  + 2);
    for(int i=1;i<=n;i++){

        int l = i, h = n+1, m;
        while(l< h){
            m = l + ( (h-l)/2 );
            if( pfx[m]-pfx[i-1] > a[i] )
                 h = m;
            else l = m +1;
        }

        table[i]++; table[l]--;
        remain[l] += a[i] - (pfx[l-1] - pfx[i-1]);
    }

    for(int i=1;i<=n;i++)
        table[i]+=table[i-1];

    for(int i=1;i<=n;i++)
        cout << (table[i]*b[i]) + remain[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--)
        solve();

    return 0;
}
