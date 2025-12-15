#include <bits/stdc++.h>

using namespace std;

int t, n;

int a[200000];
int b[200000];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i], b[i]=n-i;

    for(int i=0;i<n;i++)
        cout << b[a[i]-1] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
