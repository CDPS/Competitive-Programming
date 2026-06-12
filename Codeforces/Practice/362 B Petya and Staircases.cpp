#include <bits/stdc++.h>

using namespace std;

int t =1 , n, m, x;

bool solve(){

    cin >> n >> m;

    if(m == 0) return true;

    vector<int> a(m);
    for(int i=0;i<m;i++)
        cin >> a[i];

    sort( a.begin(), a.end());

    if(a[m-1] == n || a[0] == 1) return false;

    for(int i=0; i < m-2; i++)
        if(a[i] == a[i+1] - 1 && a[i] == a[i+2] -2)
            return false;

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}
