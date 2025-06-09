#include <bits/stdc++.h>

using namespace std;

int a[5000], x, n;

int main(){

    cin.sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;

    map<int, int> mp;
    for(int i=0;i<n;i++) cin >> a[i], mp[a[i]] = i+1;


    for(int i=0; i< n;i++){
        for(int j=i+1;j<n;j++){
            int t = x - (a[i] + a[j]);
            if( mp.count(t) && mp[t]> j+1 ){
                cout << i + 1 << " " << j + 1 << " " << mp[t] << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}
