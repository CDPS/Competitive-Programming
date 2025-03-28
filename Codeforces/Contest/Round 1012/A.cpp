#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    long long x, y, a;
    cin >> t;
    while(t--){
        cin >> x >> y >> a;
        cout << ( x> a- ((a/(x+y))*(x+y)) ? "NO" : "YES" ) << "\n";
    }

    return 0;
}
