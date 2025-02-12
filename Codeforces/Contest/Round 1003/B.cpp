#include <bits/stdc++.h>

using namespace std;

bool solve(string &s){
    for(int i=1;i<s.size();i++)
        if(s[i]==s[i-1]) return true;
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    string s;
    cin >> t;

    while(t--){
        cin >> s;
        cout << ( (solve(s))? 1 : s.size()) << "\n";
    }
    return 0;
}
