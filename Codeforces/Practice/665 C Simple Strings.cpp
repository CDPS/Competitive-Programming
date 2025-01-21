#include <bits/stdc++.h>

using namespace std;

bool v[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == s[i+1]){
            if(v[i])
                s[i] = (((s[i]-'a') + 1)%26)+'a';
            else
                s[i+1] = (((s[i+1]-'a') + 1)%26)+'a', v[i+1] = 1;
        }
    }

    cout << s << "\n";

    return 0;
}
