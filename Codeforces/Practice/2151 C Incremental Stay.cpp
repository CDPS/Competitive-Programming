#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll     a[400001];
ll   pfx[400001];
ll  pfxo[400001];
ll  pfxe[400001];

void solve(){

    cin >> n;
    for(int i=1;i<=2*n;i++){
        cin >> a[i];
        pfx[i] = pfxo[i] = pfxe[i] = 0;
    }

    for(int i=1;i<=2*n;i++){
        pfx[i] = a[i] + pfx[i-1];

        if(i%2) pfxo[i] = a[i];
        else    pfxe[i] = a[i];

        pfxo[i] += pfxo[i-1];
        pfxe[i] += pfxe[i-1];
    }

    for(int i=1;i<=n;i++){

        ll ans =  pfx[2*n]-pfx[2*n-i] -pfx[i];
        int l = i + 1, r = 2*n- i;
        if (l <= r) {
            ll odd_sum  = pfxo[r] - pfxo[l-1];
            ll even_sum = pfxe[r] - pfxe[l-1];
            ans = (i%2)? ans + (even_sum-odd_sum) : ans + (odd_sum-even_sum);
        }
        cout << ans << " \n"[i==n];
    }

}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
