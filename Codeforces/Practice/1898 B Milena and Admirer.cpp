#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[200000];

ll solve(){

    cin >> n;
    for(int i=0; i < n; i++) cin >> a[i];

    ll R = a[n-1];
    ll ans = 0;
    for(int i=n-2; i>=0; i--){
        if(a[i] > R ){
            ll P = (a[i]/R) + (a[i]%R !=0);
            ans+= P - 1;
            R = a[i]/P;
        }
        else R = a[i];
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
