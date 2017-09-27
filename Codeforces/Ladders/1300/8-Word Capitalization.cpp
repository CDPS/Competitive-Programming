#include <bits/stdc++.h>

using namespace std;

char r[26];

int main(){
    string s;
    char a='a',b='A';

    for(int i=0;i<26;i++){
        r[ a+i -'a']=b+i;
    }

    cin >> s;

    int i=0;
    if(s[0] >=97) { cout << r[ s[0] - 'a' ]; i++;}
    for(;i<s.size();i++){ cout << s[i]; }
    cout << "\n";
    return 0;
}
