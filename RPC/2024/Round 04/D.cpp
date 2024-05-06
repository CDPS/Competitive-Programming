#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
}

int main(){

    string a, b;

    cin >> a >> b;

    char v1 = '#';
    string ma = "";
    ma+=a[0];
    for(int i=1;i < a.size();i++){
        if(isVowel(a[i])){ v1 = a[i]; break;}
        ma += a[i];
    }

    char v2 = '#';
    string mb = "";
    mb+=b[b.size()-1];
    for(int i= b.size()-2;i >=0;i--){
        if(isVowel(b[i])){ v2 = b[i]; break;}
        mb =  b[i] + mb;
    }

    if(v2 != '#')
        cout  << ma + v2 + mb << "\n";
    else if( v1 != '#')
        cout  << ma + v1 + mb << "\n";
    else
        cout  << ma + 'o' + mb << "\n";

    return 0;
}
