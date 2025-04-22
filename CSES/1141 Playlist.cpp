#include <bits/stdc++.h>

using namespace std;

int a[200000];
map<int, int> mp;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 0;
    for(int i=0, j = 0; j < n ; j++){
        mp[a[j]]++;
        while(i < n && mp[a[j]]== 2 ) mp[ a[i++] ]--;
        ans= max(ans, j-i+1);
    }

    cout << ans  << "\n";

    return 0;
}


