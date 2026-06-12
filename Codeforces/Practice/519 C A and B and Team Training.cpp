#include <bits/stdc++.h>

using namespace std;

int t = 1, x, y ;

int solve(){

    cin >> x >> y;

    return min({x, y, (x + y) / 3});
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
