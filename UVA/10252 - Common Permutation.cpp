#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string a,b;

    while(getline(cin,a)){
          getline(cin,b);

        map<char,int > mp;
        for(int i=0;i<a.size();i++) mp[a[i]]++;

        string r = "";
        for(int i=0;i<b.size();i++){
            if(mp[b[i]]>0)
                r+= b[i],mp[b[i]]--;
        }
        sort(r.begin(),r.end());
        cout << r << "\n";
    }
    return 0;
}
