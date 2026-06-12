#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = 2e18;

ll a;
int t, n, m, coins[2];

ll solve(){

    cin >> a >> m >> coins[0] >> coins[1];

    string sa  = to_string(a);
    int n = sa.size();


    vector<string> candidates;
    for(int i=1; i<=n+1; i++){
        if(coins[0] !ll= 0 ){
            candidates.push_back(to_string(coins[0]) + string(i-1, coins[1] + '0' ));
            candidates.push_back(string(i, coins[0] + '0'));
        }

        if(coins[1] != 0 ){
            candidates.push_back(to_string(coins[1]) + string(i-1, coins[0] + '0'));
            candidates.push_back(string(i, coins[1] + '0'));
        }
    }

    string prefix = "";
    for(int i = 0; i < n; i++){
        int d = sa[i] - '0';

        if(i > 0 || coins[0] != 0){
            candidates.push_back(prefix + to_string(coins[0]) + string( n-i-1 , coins[1] + '0'));
            candidates.push_back(prefix + to_string(coins[0]) + string( n-i-1 , coins[0] + '0'));
        }

        if(i > 0 || coins[1] != 0){
            candidates.push_back(prefix + to_string(coins[1]) + string( n-i-1 , coins[0] + '0'));
            candidates.push_back(prefix + to_string(coins[1]) + string( n-i-1 , coins[1] + '0'));
        }

       if(d == coins[0] || d == coins[1]){
            prefix += sa[i];
        } else {
            break;
        }
    }

    if (prefix.size() == n)
        candidates.push_back(prefix);

    if (coins[0] == 0)
        candidates.push_back("0");

    ll ans = oo;
    for (string  s : candidates) {
        if (s.size() > 18) continue;
        ll x = stoll(s);
        ans = min(ans, abs(a - x));
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
