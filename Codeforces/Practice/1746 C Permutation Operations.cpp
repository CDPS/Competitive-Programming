#include <bits/stdc++.h>

using namespace std;

int t, n, x;
int pos[100001];

void solve(){

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> x, pos[x] = i;

    for(int i= 1;i<=n;i++)
        cout << pos[n-i+1]+1 << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        solve();

    return 0;
}
