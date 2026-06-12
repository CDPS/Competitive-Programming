#include <bits/stdc++.h>

using namespace std;

int t, n, m, k;

int a[100001];

int solve(){

    cin >> n >> m >> k;

    int big   = max(k-1, n-k);
    int small = min(k-1, n-k);

    int ans = 1;
    for (int x = 1; x <= big; x++) {
        int cost =  (2 * x - 1);
        if (cost > m) break;

        int y = min({ m - cost, x, small});
        ans = max(ans, 1 + x + y);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
