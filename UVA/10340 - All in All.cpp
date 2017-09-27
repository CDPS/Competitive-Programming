#include <bits/stdc++.h>

using namespace std;

int main(){

    string s,t;

    while(cin >> s >> t){

        int i=0;
        for(int j=0;j<t.size() && i < s.size();j++){
            if(t[j]==s[i])i++;
        }
        if(i==s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
