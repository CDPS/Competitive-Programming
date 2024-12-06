#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m; string s;
    cin >> t;

    while(t--){

        cin >> n >> m;

        int acc = 0;
        int ans =0;
        for(int i=0;i<n;i++){
            cin >> s;
            if(s.size() + acc <= m)
                ans++;
            acc += s.size();
        }

        cout << ans << "\n";
    }
    return 0;
}
