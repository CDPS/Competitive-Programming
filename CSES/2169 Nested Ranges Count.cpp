#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, l, r;

    cin >> n;

    vector<ll> range;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        range.push_back(a[i].first);
        range.push_back(a[i].second + 1);
    }

    sort(range.begin(), range.end());
    range.resize(unique(range.begin(), range.end()) - range.begin());


    map<int, int> mp;
    for(int i=0;i<range.size();i++)
        mp[range[i]] = i;


    for(int i=0;i<n;i++){

        mp[a[i].first];
        mp[a[i].second];
    }

    return 0;
}
