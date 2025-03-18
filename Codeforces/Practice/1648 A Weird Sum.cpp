#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get(vector<int>& a) {

    sort(a.begin(), a.end());

    ll ans = 0, acc = 0;
    for (int i = 0; i < a.size(); i++)
        ans += (ll)i * a[i] - acc, acc += a[i];

    return ans;
}

int main() {

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, m, x;
    cin >> n >> m;

    map<int, vector<int>> r, c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++) {
            cin >> x;
            r[x].push_back(i), c[x].push_back(j);
        }
    }

    ll ans = 0;
    for(auto it= r.begin(); it!=r.end();it++)
        ans += get(it->second);

    for(auto it= c.begin(); it!=c.end();it++)
        ans += get(it->second);


    cout << ans << endl;
    return 0;
}
