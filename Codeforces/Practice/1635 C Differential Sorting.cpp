#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

bool check(){
    for (int i=1;i<n;i++)
        if (a[i] < a[i-1]) return false;
    return true;
}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    if(check()){
        cout << 0 << "\n";
        return;
    }

    if(a[n-1] < a[n-2] || a[n-1] < 0 ){
        cout << -1 << "\n";
        return;
    }

    cout << (n - 2) << "\n";
    for (int i=1;i<=n-2;i++)
        cout << i << " " << (n - 1) << " " << n << "\n";
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
