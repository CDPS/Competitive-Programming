#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, l, r;
    cin >> n;

    vector<pair<int, int> > v;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        v.push_back({l, 1});
        v.push_back({r,-1});
    }
    sort(v.begin(), v.end());

    int ans = 0, acc = 0;
    for(int i=0;i<2*n;i++)
        acc += v[i].second , ans = max(acc, ans);

    cout << ans << "\n";

    return 0;
}
