#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200001];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    if(a[0] == -1 && a[n-1] == -1)
        a[0] = a[n-1] = 0;
    if(a[0] == -1 && a[n-1] != -1)
        a[0] = a[n-1];
    if(a[0] != -1 && a[n-1] == -1)
        a[n-1] = a[0];

    cout << abs(a[n-1] - a[0] )<< "\n";
    for(int i=0;i<n;i++)
        cout << (  a[i]==-1? 0 : a[i] ) << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
