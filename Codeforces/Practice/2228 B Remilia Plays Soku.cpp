#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll x1, x2, n, k;

ll get(ll s, ll t){
    return min( abs(s-t), n- abs(s - t));
}

ll solve(){

    cin >> n >> x1 >> x2 >> k;

    if(n <= 3) return 1;

    return k + get(x1, x2);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
