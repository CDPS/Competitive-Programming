#include <bits/stdc++.h>

using namespace std;

bool isNegative(string s){
    if(s.size()<2)
        return 0;
    return (s[s.size()-1]=='5' && s[s.size()-2]=='3');
}

bool isFailed(string s){
     if(s.size()<2)
        return 0;
    return (s[s.size()-1]=='4' && s[0]=='9');
}

bool isNotComplete(string s){
    if(s.size()<3)
        return 0;
     return (s[0]=='1' && s[1]=='9' && s[2]=='0');
}

int main(){

    string s;

    int t;
    cin >> t;
    while(t--){
        cin >> s;

        if(s=="1" || s=="4" || s=="78"){
            cout << "+\n";
            continue;
        }

        if(isNegative(s)){
            cout << "-\n"; continue;
        }

        if(isFailed(s)){
            cout << "*\n"; continue;
        }

        if(isNotComplete(s)){
            cout << "?\n";
        }
    }
    return 0;
}
