#include <bits/stdc++.h>

using namespace std;


bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string f(string s){
    if(isVowel(s[0]))
        return s + "ay";
    else
        return s.substr(1) + s[0] + "ay";
}

int main(){

    string line;
    while(getline(cin, line)){

        stringstream ss(line);
        string s;
        ss >> s;

        cout << f(s);
        while(ss >> s)
            cout << " " << f(s);
        cout <<"\n";
    }
    return 0;
}

