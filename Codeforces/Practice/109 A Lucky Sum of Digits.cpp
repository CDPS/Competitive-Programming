#include <bits/stdc++.h>

using namespace std;

int limit = 1e6;
int n;

void solve(){

    cin >> n;

    map<int, int> mp;
    for(int i=0, j = 0;i<=n;i+=7, j++)
        mp[i] = j;

    for(int i=0, j = 0;i<=n;i+=4, j++){
        auto it = mp.find( n-i);
        if( it != mp.end() ){
            while(j--) cout << 4;
            while(it->second--) cout << 7;
            cout << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
