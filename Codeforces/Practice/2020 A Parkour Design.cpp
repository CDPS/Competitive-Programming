#include <bits/stdc++.h>

using namespace std;

int t, x, y;

bool solve(){

    cin >> x >> y;

    if(y < 0)
        return (x + 4*y) >=0 && (x + 4*y) % 3 == 0;

    if(y > 0 )
        return (x - 2*y) >=0 && (x - 2*y) % 3  == 0;

    return x%3==0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
