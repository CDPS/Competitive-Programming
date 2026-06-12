#include <bits/stdc++.h>

using namespace std;

int t =1, n, a, b;
int x[100000];

void solve(){

    cin >> n >> a >> b;
    for(int i=0;i<n;i++) cin >> x[i];

    for(int i=0;i < n; i++)
        cout << ((1ll * a * x[i] % b) / a) << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        solve();

    return 0;
}


