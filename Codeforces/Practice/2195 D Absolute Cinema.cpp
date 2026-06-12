#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;

ll f[300000];
ll a[300000];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> f[i];

    for(int i=1;i<n-1;i++)
        a[i] = (f[i-1] + f[i+1] - 2*f[i])/2;

    ll sum = (f[0] + f[n-1])/(n-1);

    a[0]   =  (sum- f[0] +f[1])/2;
    a[n-1] =  (sum- f[n-1] + f[n-2])/2;

    for(int i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
