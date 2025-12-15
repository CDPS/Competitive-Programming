#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll solve(){

    cin >> n;

    ll sum = 0, mini = 1e18, ans = -1e18, x;
    for(int i=1;i<=n;i++){
        cin >> x;
        mini = min(mini,(1ll*i*i) - i - sum );
        sum += x;
        ans  = max(ans, (1ll*i*i) + i - sum - mini);
    }

    return sum + ans ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
