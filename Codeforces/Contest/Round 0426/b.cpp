#include <bits/stdc++.h>

using namespace std;

int main(){

    map<char, pair<int,int> > mp;
    int n, k; string s;
    cin >> n >> k;
    cin >> s;

    for(int i=0;i<n;i++){
        if(mp.find(s[i])!=mp.end()) mp[s[i]].second = i;
        else mp[s[i]]= make_pair(i,i);
    }

    for(int i=0;i<n;i++){
        if( mp[ s[i] ].first == i) k--;
        if(k==-1){ cout << "YES"; return 0;}
        if( mp[ s[i] ].second== i) k++;
    }
    cout << "NO";
    return 0;
}
