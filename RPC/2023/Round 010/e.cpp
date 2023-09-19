#include <bits/stdc++.h>

using namespace std;

string toLower(string s){

    for (auto& x : s) {
        x = tolower(x);
    }
    return s;
}

int main(){

    string s;

    cin >> s;

    s = toLower(s);

    cout << s << "\n";
    for(int i=0;i<s.size()-1; i++){
        if(s[i]=='s' && s[i+1]=='s'){
            cout << s.substr(0,i) << "B" << s.substr(i+2) << "\n";
        }
    }
    return 0;
}
