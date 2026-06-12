#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, x, y;
int a[200000];

ll solve(){

    cin >> n >> x >> y;

    ll sum = 0;
    for(int i=0;i<n;i++)
        cin >> a[i], sum+=(a[i]/x)*y;

    ll ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans, sum+a[i]-((a[i]/x)*y) );

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
