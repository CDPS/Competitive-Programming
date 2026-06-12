#include <bits/stdc++.h>

using namespace std;

int t = 1, x, y;
int a[3];

int solve(){

    cin >> x >> y;

    a[0] = a[1] = a[2] = y;

    int ans = 0;
    while(a[0] < x ){
        a[0] = min(x, a[1] + a[2] - 1);
        sort(a, a + 3);
        ans++;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
