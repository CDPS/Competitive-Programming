#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int leverIndex = 0;
    long long left = 0, right =0 ;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='^'){
            leverIndex = i;
            break;
        }
    }

    for(int i=0;i<leverIndex;i++){
        if(s[i]!='='){
            left+= (s[i]-'0') * (leverIndex - i);
        }
    }

    for(int i=leverIndex+1;i<s.size();i++){
        if(s[i]!='='){
            right+= (s[i]-'0') * (i-leverIndex);
        }
    }

    if(left > right){
        cout << "left" << "\n";
    }else if( right > left){
        cout << "right" << "\n";
    }else{
        cout << "balance" << "\n";
    }
    return 0;
}
