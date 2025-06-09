#include <bits/stdc++.h>

using namespace std;

map<int,long long> mp;

const int m = 1e9 + 7;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n;
    for(int i=0;i<n;i++) cin >> x, mp[x]++;

    long long ans = 1;
    for(auto it = mp.begin(); it!=mp.end();it++)
        ans = (ans * (it->second + 1)) % m;

    cout <<(ans - 1 + m) % m << "\n";

    return 0;
}

