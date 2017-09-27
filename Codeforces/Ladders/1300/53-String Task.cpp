#include <bits/stdc++.h>

using namespace std;

bool isCons(char c){
    if(c>=97 && c<=122 && c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c!='y')
        return true;
    return false;
}

int main(){
    string s;

    cin >> s;
    string res="";

    for(int i=0;i<s.size();i++){
        if(isCons(tolower(s[i]) )){
            res+= '.';
            res+= tolower(s[i]);
        }
    }
    cout << res << "\n";
    return 0;
}
