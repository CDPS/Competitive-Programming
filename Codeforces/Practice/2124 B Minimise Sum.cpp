#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[200000];

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    if(n==2)
        return a[0] + min(a[0], a[1]);

    ll pfx = 0, minpfx = 1e18, ans = 1e18;
    for(int i=0; i < n-1;i++){
        ans = min(ans, pfx + min(minpfx, a[i] + a[i+1]) );
        minpfx = min(a[i], minpfx);
        pfx+=minpfx;
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
