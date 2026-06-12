#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n, m;

ll a[200000], bi;

void solve(){

    cin >> n >> m;

    for(int i=0; i < n; i++) cin >> a[i];

    ll gcd_total = 0;
    for(int i= 1;i < n ; i++)
        gcd_total = __gcd(gcd_total, abs(a[i]-a[0]) ) ;

    for(int i=0 ; i < m; i++){
        cin >> bi;
        cout << __gcd(a[0] + bi, gcd_total) << " \n"[i==m-1];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();
    return 0;
}
