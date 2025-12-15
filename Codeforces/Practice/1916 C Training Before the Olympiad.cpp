#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll a[200001];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    cout << a[0];

    ll sum = a[0], odds = a[0]%2;
    for(int i=1;i<n;i++){
        odds += a[i]%2;
        sum  +=a[i];
        cout << " " << sum - odds/3 - (odds%3==1);
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
