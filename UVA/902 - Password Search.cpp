#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int m; string s;

    while(cin >> m >> s){
        int maxi = 0;
        string ans = "";
        unordered_map<string, int> mp;
        for(int i=0;i<s.size()-m;i++){
            string aux = "";
            for(int j=0;j<m;j++) aux+= s[i+j];
            mp[aux]++;
            if(mp[aux] > maxi){
                maxi = mp[aux];
                ans = aux;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
