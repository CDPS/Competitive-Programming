#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;
string s;

ll solve(){

    cin >> n;

    vector<ll> a(n);
    vector<ll> pfx(n + 1, 0);

    for(int i = 0; i < n; i++)
        cin >> a[i], pfx[i + 1] = pfx[i] + a[i];
    cin >> s;

    ll ans = 0, fixed_sum = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1') {
            ans = max(ans, fixed_sum + pfx[i]);
            fixed_sum += a[i];
        }
    }

    return max(ans, fixed_sum);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
