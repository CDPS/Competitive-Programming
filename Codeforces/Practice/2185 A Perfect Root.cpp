#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[3000];

void solve(){

    cin >> n;
    for(int i=1; i <=n ;i++)
        cout << i << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}



