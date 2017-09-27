#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<string> ss;
vector<string> rules;
string s;

string rule;

void backtrack(int idx ,string acc){

    if(idx==rule.size()){
        cout << acc << "\n";
        return;
    }

    if(rule[idx]=='#'){
        for(int i=0;i<n;i++)
            backtrack(idx+1, acc + ss[i]);
    }else{
        for(char  i='0';i<='9';i++)
            backtrack( idx+1, acc + i);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >>n ){

        for(int i=0;i<n;i++){ cin >> s; ss.push_back(s); }

        cin >>m;
        for(int i=0;i<m;i++){cin >> s; rules.push_back(s);}

        cout << "--\n";
        for(int i=0;i<rules.size();i++){
            rule=rules[i]; backtrack(0,"");
        }
        ss.clear(); rules.clear();
    }
    return 0;
}
