#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[200000];

void solve(){

    cin >> n;
    for(int i=0; i < n ; i++)
        cin >> a[i];
    
    ll ans = a[0], pfx = a[0];
    
    cout << ans;
    for(int i=1; i < n; i++){
        pfx += a[i];
        ans = min(ans, pfx / (i + 1));
        cout << " " << ans;
    }
    
    cout << "\n";
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        solve();
    return 0;
}