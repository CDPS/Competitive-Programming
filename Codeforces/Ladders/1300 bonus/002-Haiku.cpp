#include <bits/stdc++.h>

using namespace std;

bool isVocal(char c){
    return c == 'a' || c=='e' || c=='i'|| c=='o'|| c=='u';
}

bool check(string s, int n){
    int syllables = 0;
    for(int i=0;i<s.size();i++){
        if(isVocal(s[i])){
            syllables++;
        }
    }
    return syllables == n;
}

int main(){

    string line;
    bool result = true;

    getline(cin,line);
    result&=check(line,5);

    getline(cin,line);
    result&=check(line,7);

    getline(cin,line);
    result&=check(line,5);

    cout << ((result)? "YES": "NO") << "\n";
    return 0;
}

