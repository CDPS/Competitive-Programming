#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, u , v;
    cin >> t;
    while(t--){

        cin >> n ;

        vector<pair<int, int>> a;
        for(int i=0;i<n-1;i++)
            cin >> u >> v, a.push_back({u,v});


        cout << ans << "\n";
    }
    return 0;
}
