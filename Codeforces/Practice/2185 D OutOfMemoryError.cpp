#include <bits/stdc++.h>

using namespace std;

int t, n, m, h, idx, val;

void solve(){

    cin >> n >> m >> h;

    vector<int> a(n+1, 0), version(n+1,0), curr(n+1, 0);
    for(int i=1; i <=n; i++)
        cin >> a[i], curr[i] = a[i];


    int curr_version = 0;
    while(m--){
        cin >> idx >> val;

        if(version[idx] != curr_version)
             curr[idx] = a[idx], version[idx] = curr_version;

        curr[idx] += val;
        if( curr[idx]> h )
            curr[idx] = a[idx], curr_version++;

        version[idx] = curr_version;
    }

    for(int i=1;i<=n;i++)
        cout <<( (version[i]==curr_version)? curr[i] : a[i] )<< " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
