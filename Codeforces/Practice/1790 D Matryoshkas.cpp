#include <bits/stdc++.h>

using namespace std;

int n;
int a[200000];

int solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);

    int ans = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp[a[i]-1] > 0 ) mp[a[i]-1]--;
        else ans++;
        mp[a[i]]++;
    }

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
