#include <bits/stdc++.h>

using namespace std;

int t, n;

void solve(){

    cin >> n;

    vector<int> a(n);
    for(int i= 0 ; i < n ; i++) cin >> a[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if(n > a.size()){
        cout << -1 << "\n";
        return;
    }

    for(int i=n-1; i>=0; i--)
        cout << a[i] << " \n"[i==0];
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
