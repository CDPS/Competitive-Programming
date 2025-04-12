#include <bits/stdc++.h>

using namespace std;

int n,k,x;
int a[200000];

void solve(){

    map<int, int> mp;
    for(int i=0;i<n;i++){
       if( mp.find(k-a[i]) != mp.end() ){
            cout << mp[k-a[i]] << " " << i+1 << "\n";
            return;
       }
       mp[a[i]] = i + 1;
    }

    cout << "IMPOSSIBLE" << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >>a[i];

    solve();

    return 0;
}
