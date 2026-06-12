#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second

int n, r, t, x, y;

ll solve(){

    cin >> n >> r >> t;

    vector<pair<int,int>> v;

    ll extra = 0, needed = 0;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        if(x > t ) extra += x- t;
        if(x< t)   needed+= t - x;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), [&](auto a, auto b) {
        if(a.s == b.s)
            return a.f < a.f;
        return a.s < b.s;
    });

    needed = max(0ll, needed - extra);

    ll ans = 0;
    for(int i=0; i < v.size(); i++){
        ll take = min(r - v[i].f + 0ll, needed);
        ans+= take*v[i].s;
        needed-=take;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
