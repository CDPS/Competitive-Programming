#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;

    cin >> t;
    while(t--){

        cin >> n;

        vector<int> e, o;
        for(int i=0;i<n;i++){
            cin >> x;
            if(x%2) o.push_back(x);
            else    e.push_back(x);
        }

        sort(e.begin(), e.end(), greater<int>());
        sort(o.begin(), o.end(), greater<int>());

        if(e.size() == 0 ){
            cout << o[0] << "\n"; continue;
        }

        if(o.size() == 0 ){
            cout << e[0] <<  "\n"; continue;
        }

        long long ans = o[0];
        for(int i=1;i<o.size();i++)
            ans += o[i] -1;

        for(int i=0;i<e.size();i++)
            ans += e[i];

        cout << ans << "\n";
    }
    return 0;
}
