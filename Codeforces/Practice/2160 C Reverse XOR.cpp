#include <bits/stdc++.h>

using namespace std;

int t, n, x;

bool solve(){

    cin >> n;

    if(n == 0)
        return true;

    vector<int> a;

    int r = 0;
    while( (n&(1<<r)) == 0 ) r++;

    int l = 30;
    while( (n&(1<<l)) == 0 ) l--;

    for(int i=r; i <= l; i++)
        a.push_back( (n&(1<<i)) == 0? 0 : 1 );

    int m = a.size();
    for(int i=0;i<m;i++)
        if(a[i] != a[m-1-i])
            return false;

    return (m%2)? a[m/2] == 0 : true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}

