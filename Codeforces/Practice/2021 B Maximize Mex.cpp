#include <bits/stdc++.h>

using namespace std;

int t, n, x, val;


int solve(){

    cin >> n >> x;

    map<int, int> mp;
    for(int i=0;i<n;i++)
        cin >> val, mp[val]++;

    for(int i=0; i < n + 1  ; i++){
        if(mp[i] == 0 && mp[i-x] == 0) return i;
        if(mp[i-x] > 0) mp[i]+=mp[i-x];
        mp[i]--;
    }

    return n;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve()  << "\n";

    return 0;
}



