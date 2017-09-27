#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){ printf("0"); }
        else if(s[i+1]=='.') {printf("1");i++;}
        else{printf("2"); i++;}
    }
    printf("\n");
    return 0;
}
