#include <bits/stdc++.h>

using namespace std;

int t, n, x;

long long solve(){

    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin >> a[i];

    map<int,int> mp;

    long long ans = 0;
    for(int i=0;i<n;i++)
        ans+=mp[a[i]-i], mp[a[i]-i]++;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

