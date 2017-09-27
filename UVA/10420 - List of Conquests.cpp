#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    map<string,int> mp;
    int t; string s;
    cin >> t;
    while(t--){
        cin >> s;
        mp[s]++;
        getline(cin,s);
    }
    map<string,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
        cout << it->first << " " << it->second << "\n";
    return 0;
}
