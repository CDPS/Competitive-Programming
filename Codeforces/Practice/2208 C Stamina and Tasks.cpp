#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
int t, n;

double solve(){

    cin >> n;

    vector< pair<int, int> > v (n + 1);
    for(int i=1; i <=n; i++ )
        cin >> v[i].f >> v[i].s;

    vector<double> dp(n + 1);
    dp[n] = v[n].f;

    for(int i= n - 1; i>=1; i--)
        dp[i] = max(dp[i+1], v[i].f + (dp[i+1] * (1.0 - (v[i].s / 100.0))));

    return dp[1];
}

int main(){


    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(10);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
