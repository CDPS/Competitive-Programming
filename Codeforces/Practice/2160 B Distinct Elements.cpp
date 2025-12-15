#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll   b[100001];
ll ans[100001];

int t, n;
void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];

    ll curr = 1;
    for(int i=1;i<=n;i++){
        ll target =  i - (b[i]-b[i-1]);
        if(target == 0 )
            ans[i] = curr++;
        else
            ans[i] = ans[target];
    }

    for(int i=1; i<=n; i++)
        cout << ans[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

