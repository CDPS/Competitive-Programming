#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[100000];

void solve(){

    cin >> n;
    for(int i=0; i < n; i++)
        cin >> a[i];

    sort(a , a + n);

    ll part1 = 0, part2 = 0;
    for(int i=0;i<n;i++){
        part1 += a[i];
        part2 += a[i]*( (2*i) - n + 1 );
    }

    ll ans = part1 + 2*part2;
    ll div = __gcd(ans, 1ll*n);

    cout << ans/div << " " << n/div << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
