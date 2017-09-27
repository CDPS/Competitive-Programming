#include <bits/stdc++.h>

using namespace std;

string a = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){

    string s,res;

    while(getline(cin, s)){
        res ="";

        for(int i=0;i<s.size();i++){

            if(s[i]==' '){ res+=' '; continue; }

            for(int j=0;j<a.size();j++){
                if(a[j]==s[i]){
                    res+= a[j-1];
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}
