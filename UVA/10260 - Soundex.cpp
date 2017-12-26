#include <bits/stdc++.h>

using namespace std;

string soundex= "01230120022455012623010202";

int main(){

    string s;

    while(cin >> s){

        string ans= "";
        ans = (soundex[ s[0]-'A']!='0')?  ans + soundex[ s[0]-'A']:"";

        for(int i=1;i<s.size();i++)
            if(soundex[ s[i] - 'A' ]!='0' && soundex[ s[i] -'A' ]!= soundex[ s[i-1]-'A' ] )
                ans= ans + soundex[ s[i]-'A' ];

        cout << ans << "\n";
    }

    return 0;
}
