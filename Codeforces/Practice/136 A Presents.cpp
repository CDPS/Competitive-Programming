#include <bits/stdc++.h>

using namespace std;

int n,x;
int a[101];

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        a[x] = i;
    }

    for(int i=1;i<=n;i++)
        cout << a[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}

