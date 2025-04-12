#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, l, r;
    cin >> n;

    vector<pair<int, int> > v;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        v.push_back({r, l});
    }
    sort(v.begin(), v.end());

    int ans = 0, mini = 0;
    for(int i=0;i<n;i++)
        if(v[i].second >= mini)
            mini = v[i].first, ans++;


    cout << ans << "\n";

    return 0;
}
