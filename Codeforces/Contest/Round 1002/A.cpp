#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;
    while(t--){

        cin >> n;

        set<int> sta, stb;
        for(int i=0;i<n;i++) cin >> x, sta.insert(x);
        for(int i=0;i<n;i++) cin >> x, stb.insert(x);

        cout << ( sta.size()+stb.size()>=4? "YES" : "NO" ) << "\n";
    }
    return 0;
}
