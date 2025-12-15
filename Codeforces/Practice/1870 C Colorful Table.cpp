#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int t, n, k, x;


void solve(){

    cin >> n >> k;

    vector<int>  pfx(k+1,  oo);
    vector<int>  sfx(k+1, -oo);
    vector<bool> present(k+1, 0);

    for(int i=0;i<n;i++){
        cin >> x;
        pfx[x] = min(pfx[x], i);
        sfx[x] = max(sfx[x], i);
        present[x] = true;
    }

    for(int i=k-1;i>=1;i--)
        pfx[i] = min(pfx[i], pfx[i+1]);

    for(int i=k-1;i>=0;i--)
        sfx[i] = max(sfx[i], sfx[i+1]);

    for(int i=1;i<=k;i++)
        cout << ( present[i]? 2*(sfx[i] - pfx[i] + 1) : 0 ) << " \n"[i==k];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
