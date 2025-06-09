#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct task{
    ll a, d;
    task(ll a, ll d): a(a), d(d){}
    bool operator < (const task &t )const {
        return (a == t.a)? d > t.d: a < t.a;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, a, d;
    cin >> n;

    vector<task> v;
    for(int i=0;i < n; i++)
        cin >> a >> d, v.push_back(task(a,d));

    sort(v.begin(), v.end());

    ll ans = 0, acc =0;
    for(int i=0;i<n;i++){
       acc+= v[i].a;
       ans+= v[i].d - acc;
    }

    cout << ans << "\n";

    return 0;
}
