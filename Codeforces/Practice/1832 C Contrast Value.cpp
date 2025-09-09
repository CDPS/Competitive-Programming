#include <bits/stdc++.h>

using namespace std;

int n;

int solve(){

    cin >> n;

    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0] = -1; a[n+1] = -1;

    a.erase(unique(a.begin(), a.end()), a.end());

    if(a[1] > a[2]) a[0] = -1;
    if(a[1] < a[2]) a[0] = 1e9+7;

    int m =  a.size();

    if(a[m-2] > a[m-3])  a[m-1] = -1;
    if(a[m-2] < a[m-3] ) a[m-1] = 1e9+7;

    int ans = 0;
    for(int i=1;i<m-1;i++)
        if( (a[i] > a[i-1] && a[i] > a[i+1] ) ||
            (a[i] < a[i-1] && a[i] < a[i+1] ))
            ans++;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
