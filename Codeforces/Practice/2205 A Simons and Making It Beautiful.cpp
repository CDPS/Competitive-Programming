#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[500];

void solve(){

    cin >> n;

    int idx = 0;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        if(a[i] == n)
            idx = i;
    }

    swap(a[0], a[idx]);
    for(int i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
}
