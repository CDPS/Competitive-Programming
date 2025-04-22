#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll, ll> a[200000];
ll sfx[4000002];
ll ans[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin >> n;
    vector<ll> range;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        range.push_back(a[i].first);
        range.push_back(a[i].second + 1);
    }

    sort(range.begin(), range.end());
    range.resize(unique(range.begin(), range.end()) - range.begin());

    map<ll, int> mp;
    for(int i=0;i<range.size();i++)
        mp[range[i]] = i;

    for(int i = 0; i < n; i++) {
        sfx[ mp[a[i].first] ]++;
        sfx[ mp[a[i].second + 1] ]--;
    }

    for(int i = 1; i < range.size(); i++)
        sfx[i] += sfx[i-1];

    for (int i = 0; i + 1 < range.size(); i++)
        ans[sfx[i]] += range[i + 1] - range[i];

    for(int i=1;i<=n;i++)
        cout << ans[i] << " \n"[i==n];

    return 0;
}
