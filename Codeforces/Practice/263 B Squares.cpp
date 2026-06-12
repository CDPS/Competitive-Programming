#include <bits/stdc++.h>

using namespace std;

int t =1;
int n, k, x;
int   a[51];

void solve(){

    cin >> n  >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(a, a + n, greater<int>() );

    if(k > n){
        cout << -1 << "\n";
        return;
    }

    cout << a[k-1] << " " << 0 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        solve();

    return 0;
}

