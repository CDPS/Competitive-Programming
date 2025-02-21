#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    long long x, sum = 0, ans = 0;
    cin >> n >> x;

    map<long long, int> mp; mp[0]++;
    for(int i=0;i<n;i++){
        cin >> k;
        sum+= k;
        if(mp[sum-x]) ans+= mp[sum-x];
        mp[sum]++;
    }

    cout << ans << "\n";
    return 0;
}
