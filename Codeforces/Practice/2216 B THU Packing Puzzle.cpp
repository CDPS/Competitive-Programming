#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T, H, U;

ll solve(){

    cin >> T >> H >> U;

    ll ans = 0;

    ll min_T_U = min(T, U);
    ans+= 4*min_T_U;
    T-= min_T_U;
    U-= min_T_U;

    ll min_2T_H = min(T / 2, H);
    ans += 7 * min_2T_H;
    T -= 2 * min_2T_H;
    H -= min_2T_H;

    ll min_T_H = min(T, H);
    ans+= 5*min_T_H;
    T-= min_T_H;
    H-= min_T_H;

    if (T > 0)
        ans += 2 * T + 1;

    return ans + (3*H) + (3*U);
}

int t;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
