#include <bits/stdc++.h>

using namespace std;

int main(){

    int k;
    cin >> k;
    string s;

    cin >> s;
    map<char,int> mp;
    for(int i=0;i<s.size();i++) mp[ s[i]]++;

    map<char,int>::iterator it;

    for(it=mp.begin();it!=mp.end();it++)
        if( (it->second)%k ){ cout << "-1\n"; return 0;  }

    string ans="";
    for(it=mp.begin();it!=mp.end();it++)
        for(int i=0;i< (it->second)/k;i++) ans+=it->first;

    string cur = ans; ans ="";
    int j=0;
    while(j<k){ ans+=cur; j++;}
    cout << ans << "\n";
    return 0;
}
