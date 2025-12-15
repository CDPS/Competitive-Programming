#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int t, n, k, l, r;

ll a[200000];

void add(map<ll, int> &mp, ll x){ mp[x]++; }
void del(map<ll, int> &mp, ll x){ if(--mp[x]==0) mp.erase(x); }

ll solve() {

    cin >> n >> k >> l >> r;

    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    map<ll, int> mp1, mp2;
    for(int L = 0, RK = 0, RK1 = 0; L < n; L++) {

        while (RK < n && mp1.size() < k)
            add(mp1, a[RK++]);

        while (RK1 < n) {
            if (mp2.size() == k && mp2.count(a[RK1]) == 0)
                break;
            add(mp2, a[RK1++]);
        }

        if (mp1.size() < k) break;

        int lo = max(RK  - 1,L + l - 1);
        int hi = min(RK1 - 1,L + r - 1);
        if (lo <= hi)
            ans += hi - lo + 1;

        del(mp1, a[L]), del(mp2, a[L]);
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

