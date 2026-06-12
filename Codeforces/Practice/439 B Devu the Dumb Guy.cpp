#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n, x;
int a[100000];

ll solve(){

    cin >> n >> x;
    for(int i=0; i < n; i ++)
        cin >> a[i];

    sort(a, a + n);

    ll ans = 0;
    for(int i=0; i < n; i++){
        ans += 1ll*x*a[i];
        x= max(1, x -1);
    }

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
