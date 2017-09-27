#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);

    string line,word; stringstream ss;
    getline(cin,line);
    ss << line;

    map<char,int> mp1,mp2;

    while(ss >> word ){
        for(int i=0;i<word.size();i++)
            mp1[word[i]]++;
    }

    ss.clear();
    getline(cin,line);
    ss << line;
    while(ss >> word ){
        for(int i=0;i<word.size();i++)
            mp2[word[i]]++;
    }
    map<char,int>::iterator it;

    for(it=mp2.begin();it!=mp2.end();it++){
        if(mp1[it->first]<it->second){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
