#include <bits/stdc++.h>

using namespace std;


map<char,char> r;

bool isPalindrome(string s){
    string t = s;
    reverse(t.begin(),t.end());
    return t==s;
}

bool isMirrored(string s){
    string t="";
    for(int i=0;i<s.size();i++)
        t+=r[s[i]];
    reverse(t.begin(),t.end());
    return t==s;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    r['A']='A';r['E']='3';r['H']='H';r['I']='I';r['J']='L';r['L']='J';r['M']='M';
    r['O']='O'; r['S']='2';r['T']='T';r['U']='U';r['V']='V';r['W']='W';r['X']='X';
    r['Y']='Y';r['Z']='5';r['1']='1';r['2']='S';r['3']='E';r['5']='Z';r['8']='8';

    string s;
    while(cin >> s){

        bool f1= isPalindrome(s); bool f2= isMirrored(s);
        if(f1 && f2)
            cout << s << " -- is a mirrored palindrome.\n";
        else if(f1 && !f2)
            cout << s << " -- is a regular palindrome.\n";
        else if(!f1 && f2)
            cout << s << " -- is a mirrored string.\n";
        else
            cout << s << " -- is not a palindrome.\n";
        cout << "\n";
    }
    return 0;
}
