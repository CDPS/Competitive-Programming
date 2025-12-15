#include <bits/stdc++.h>

using namespace std;

int t, x, y, z;

bool solve(){
    cin >> x >> y >> z;
    return ( (x&y)==(x&z)) && ( (x&y)==(y&z) ) && ( (x&z)==(y&z));
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}

