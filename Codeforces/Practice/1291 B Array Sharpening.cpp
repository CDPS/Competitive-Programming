#include <bits/stdc++.h>

using namespace std;

int a[300000];
int t, n;

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    int l = 0, r = n -1;
    while(l < n && a[l]  >=  l )    l++;
    while(r >=0 && a[r]  >=  n-1-r) r--;


    if( l == n || r == -1) return true;

    r++, l--;
    if( r <= l ) return true;

    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}

