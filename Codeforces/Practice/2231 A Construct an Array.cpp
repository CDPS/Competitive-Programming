#include <bits/stdc++.h>

using namespace std;

int t, n;

int a[501];

void solve(){

    cin  >> n;

    for(int i=1, j= n; i<=n; i+=2)
        a[i] = j--;
    for(int i=2, j= 2*n; i<=n; i+=2)
        a[i] = j--;
    for(int i=1; i<=n; i++)
        cout << a[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
