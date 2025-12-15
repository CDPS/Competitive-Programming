#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, y, r;

int solve(){

    cin >> n >> y >> r;

    return min(n, (y/2) + r );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


