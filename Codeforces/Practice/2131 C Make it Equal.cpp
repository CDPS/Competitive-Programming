#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k, x, mod;
    cin >> t;

    while(t--){

        cin >> n >> k;

        map<int, int> mp;
        for(int i=0;i<n;i++){
            cin >> x;
            mod = x %k ;
            mp[ min(mod, k-mod)]++;
        }

        for(int i=0;i<n;i++){
            cin >> x;
            mod = x %k ;
            mp[ min(mod, k-mod)]--;
        }

        bool ans = true;
        for(auto it= mp.begin(); it!=mp.end();it++){
            if(it->second !=0){
                ans= false;
                break;
            }
        }

        cout << (ans? "YES" : "NO" ) << "\n";
    }
    return 0;
}
