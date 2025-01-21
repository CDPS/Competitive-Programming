#include <bits/stdc++.h>

using namespace std;

int xs[200000], ys[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,x,y, k;
    cin >> t;
    while(t--){

        cin >> n >> x >> y;

        map<pair<int,int>, int> mp;

        for(int i=0;i<n;i++)
            cin >> k, xs[i] = k%x, ys[i] = k%y;

        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += mp[{(x-xs[i])%x, ys[i]}];
            mp[{xs[i],ys[i]}]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
