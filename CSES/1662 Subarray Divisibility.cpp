#include <bits/stdc++.h>

using namespace std;


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n; long long sum = 0, ans = 0, k;

    cin >> n;
    map<long long, int> mp; mp[0]++;

    for(int i=0;i<n;i++){
        cin >> k;
        sum = ((sum+k)%n+ n )%n;
        if(mp[sum]) ans+= mp[sum];
        mp[sum]++;
    }

    cout << ans << "\n";
    return 0;
}
