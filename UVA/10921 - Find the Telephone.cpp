#include <bits/stdc++.h>

using namespace std;

string r="22233344455566677778889999";

int main(){
    string s,res;

    while(getline(cin,s)){
        res="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z')
                res+=r[ s[i]- 'A' ];
            else
                res+=s[i];
        }
        cout << res << "\n";
    }
    return 0;
}
