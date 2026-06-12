#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;

    map<int, int> mp;
    for(int i=0 ; i< n; i++)
        cin >> x, mp[x]++;

    vector<int> freq;
    for(auto u : mp)
        freq.push_back(u.second);
    sort(freq.begin(), freq.end());

    int ans = 1e9;
    for(int i=1; i <= n; i++){
        int idx = lower_bound(freq.begin(), freq.end(), i) - freq.begin();
        int survivors = freq.size() - idx;
        ans = min(ans,  n - (survivors * i));
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
