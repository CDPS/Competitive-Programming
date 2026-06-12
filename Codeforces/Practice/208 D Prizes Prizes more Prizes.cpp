#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1,  n;

ll a[50];
ll b[5];
ll c[5];

void solve(){

    cin >> n;

    for(int i=0; i < n ;i++) cin >> a[i];
    for(int i=4; i >= 0;i--) cin >> b[i];

    ll current_points = 0;
    for(int i= 0 ; i < n; i++){
        current_points += a[i];
        for(int j = 0; j < 5; j++){
            ll amount = current_points/b[j];
            c[j]+= amount;
            current_points -= amount*b[j];
        }
    }

    for(int i=4; i >= 0;i--)
        cout << c[i] << " \n"[i==0];
    cout << current_points << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
