#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    string s;
    cin >> t;

    while(t--){

        cin >> s;

        string ans = "";
        for(int i=0;i<s.size()-2;i++)
            ans+= s[i];

        cout << ans+"i" << "\n";
    }
    return 0;
}
