#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+ n);

    swap(a[0], a[n-1]);
    for(int i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
