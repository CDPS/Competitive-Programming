#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;

    cin >> t;

    while(t--){

        cin >> n;

        vector<int> v; v.push_back(-1);
        for(int i=0;i<n;i++){
            cin >> x;
            if(x!=v.back())
                v.push_back(x);
        }
        v.push_back(-1);

        int ans = 0;
        for(int i=1;i<v.size()-1;i++)
            if(v[i]> v[i-1] && v[i] > v[i+1])
                ans++;

        cout << ans << "\n";
    }

    return 0;
}


