#include <bits/stdc++.h>

using namespace std;

map<char,double> mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,m;
    cin >> t;
    while(t--){
        cin >> m;
        char c; double p;
        for(int i=0;i<m;i++){
            cin >> c >> p;
            mp[c]= p/100.0;
        }
        cin >> m; cin.ignore();
        string s;
        double res=0;
        while(m--){
            getline(cin,s);
            for(int i=0;i<s.length();i++){
                if(s[i]!=' '){
                    res+=mp[s[i]];
                }
            }
        }
        cout << fixed << setprecision(2) << res << "$" << "\n";
        mp.clear();
    }
    return 0;
}
