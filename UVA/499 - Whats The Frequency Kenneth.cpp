#include <bits/stdc++.h>

using namespace std;

int main(){

    string line;int maxi;
    string ans;
    while(getline(cin,line)){
        maxi=-1;
        map<char,int> mp;
        for(int i=0;i<line.size();i++)
            if( (line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z') )
                mp[line[i]]++,maxi=max(mp[line[i]],maxi);
        map<char,int>::iterator it;
        ans="";
        for(it=mp.begin();it!=mp.end();it++)
            if(it->second == maxi)
                ans+=it->first;
        cout << ans << " " << maxi << "\n";
    }
    return 0;
}
