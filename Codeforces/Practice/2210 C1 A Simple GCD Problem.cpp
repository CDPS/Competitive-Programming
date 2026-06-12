#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

int solve(){

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i=1; i < n-1; i++){
        int g_1 = __gcd(a[i], a[i+1]);
        int g_2 = __gcd(a[i], a[i-1]);
        long long lcm = 1ll*(g_1 / __gcd(g_1, g_2)) * g_2;
        ans += (lcm < a[i]);
    }

    ans += __gcd(a[0], a[1]) != a[0];
    ans += __gcd(a[n-1], a[n-2]) != a[n-1];
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}


