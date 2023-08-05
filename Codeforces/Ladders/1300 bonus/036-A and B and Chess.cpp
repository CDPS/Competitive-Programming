#include<bits/stdc++.h>

using namespace std;

map<char, int> mp;

int main(){

    mp['Q']=9;
    mp['R']=5;
    mp['B']=3;
    mp['N']=3;
    mp['P']=1;
    mp['K']=0;
    mp['q']=9;
    mp['r']=5;
    mp['b']=3;
    mp['n']=3;
    mp['p']=1;
    mp['k']=0;

    int white = 0;
    int black = 0;
    string s;

    for(int i=0;i<8;i++){
        cin >> s;

        for(int j=0;j<s.size();j++){
            if(s[j]=='.')
                continue;

            if(s[j]<96)
                white+= mp[s[j]];
            else
                black+= mp[s[j]];
        }
    }

    if(white > black){
        cout << "White" << "\n";
    }else if(black > white){
        cout << "Black" << "\n";
    }else{
        cout << "Draw" << "\n";
    }
    return 0;
}
