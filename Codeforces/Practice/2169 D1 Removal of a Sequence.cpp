#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll limit = 1e12;
ll x, y, k;

ll solve(){

    cin >> x >> y >> k;

    if(y == 1) return -1;

    ll pos = k;
    for(int i = 0; i < x; i++) {
        pos = pos + (pos - 1) / (y - 1);
        if (pos > limit)
            return -1;

    }

    return pos;
}

int t;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
