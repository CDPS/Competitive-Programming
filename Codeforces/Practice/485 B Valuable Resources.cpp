#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1,  n;

ll x, y;

ll solve(){

    cin >> n;

    ll max_x = -1e18, max_y = -1e18;
    ll min_x =  1e18, min_y =  1e18;
    for(int i=0; i < n; i++){
        cin >> x >> y;
        max_x = max(max_x , x);
        max_y = max(max_y , y);
        min_x = min(min_x, x);
        min_y = min(min_y, y);
    }

    return max( abs(max_x - min_x)*abs(max_x - min_x), abs(max_y - min_y)*abs(max_y - min_y) );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
