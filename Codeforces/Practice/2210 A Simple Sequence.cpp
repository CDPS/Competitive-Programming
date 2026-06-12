#include <bits/stdc++.h>

using namespace std;

int t, n;
void solve(){

    cin >> n;

    for(int i=n; i>=1;i--)
        cout << i << " \n"[i==1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

