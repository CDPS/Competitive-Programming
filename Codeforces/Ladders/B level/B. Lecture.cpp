#include <bits/stdc++.h>

using namespace std;

map<string,string> mp;

int main(){

    int n,m;
    cin >> n >>m;

    string s,t;
    for(int i=0;i<m;i++){
        cin >> s >> t;
        mp[s]=t;
    }

    for(int i=0;i<n;i++){
        cin >> s;
        cout << ( mp[s].size()< s.size() ? mp[s] : s ) << " ";
    }

    return 0;
}
