#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int n;

void solve(){

    cin >> n;

    int m  = (n*(n-1))/2;

    for(int i=0;i<m;i++) cin >> a[i];
    sort(a, a+ m);

    for(int i=0;i<m;i+= --n)
        cout << a[i] << " ";

    cout << 1000000000 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

