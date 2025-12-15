#include <bits/stdc++.h>

using namespace std;

int t, n;

string s;
string g[1000];

void solve(){

    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> g[i] , v[i] = i;

    sort(v.begin(), v.end(),
    [&](int x ,int y) {
        if(g[x][y] == '1' ) return x < y ;
        return x > y;
    });

    for(int i=0;i<n;i++)
        cout << v[i] + 1 << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
}
