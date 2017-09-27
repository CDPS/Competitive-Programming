#include <bits/stdc++.h>

using namespace std;


int main(){

    string s;
    cin >> s;

    int upper=0;
    int lower=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>=97) lower++;
        else upper++;
    }

    if(lower>=upper){
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }
    }else{
        for(int i=0;i<s.size();i++){
            s[i]=toupper(s[i]);
        }
    }
    cout << s << "\n";
    return 0;
}
