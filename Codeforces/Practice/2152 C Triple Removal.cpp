#include <bits/stdc++.h>

using namespace std;

int t, n, q, l, r;

int   a[250001];
int  dp[250001];
int pfx[250001];

void solve(){

    cin >> n >> q;

    for(int i= 1;i <=n; i++)
        cin >> a[i], pfx[i] = a[i] + pfx[i-1];

    dp[1] = 1;
    for(int i=2;i<=n;i++)
        dp[i] = (a[i]!= a[i-1])? 1 + dp[i-1] : 1;

    while(q--){

        cin >> l >> r;

        int sum1 = pfx[r] - pfx[l-1];
        int sum0 = (r-l+1) - sum1;

        if(sum1%3 !=0 || sum0%3 != 0){
            cout << -1 << "\n";
            continue;
        }

        int range = r-l+1;
        cout << (range/3) + (  range<= dp[r] ) << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
