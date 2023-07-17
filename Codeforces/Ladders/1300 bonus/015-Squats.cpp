#include <bits/stdc++.h>

using namespace std;

char invert(char c){
    return c=='x'? 'X' : 'x';
}

void getString(string &s, int amount, char c){
    for(int i=0;i<s.size() && amount >0;i++){
        if(s[i]==c ){
            s[i]=invert(c);
            amount--;
        }
    }
}

int main(){

    int n,x=0,X=0;
    string s;
    cin >> n;
    cin >> s;

    for(int i=0;i<n;i++){
        if(s[i]=='x')
            x++;
        else
            X++;
    }

    int disx = abs((n/2)-x);
    int disX = abs((n/2)-X);

    if(disx>disX)
        getString(s,  disX, 'X');
    else if(disx<disX)
        getString(s,  disx, 'x');
    else{
        if(x>X){
            getString(s,  disx, 'x');
        }else{
            getString(s,  disx, 'X');
        }
    }
    cout << min(disx,disX)  << "\n";
    cout << s  << "\n";

    return 0;
}
