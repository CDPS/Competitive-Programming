#include <bits/stdc++.h>

using namespace std;

int a[26];

int main(){

    cin.sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        memset(a, 0, sizeof a);
        string s;
        cin >> s;

        for(int i=0;i<s.size();i++) a[s[i]-'A']++;

        int ans = 0;
        bool f= true;

        while(f){

            f= a['A'-'A'] >= 3 && a['M'-'A'] >= 1 && a['R'-'A'] >= 2 &&
               a['G'-'A'] >= 1 && a['I'-'A'] >= 1 && a['T'-'A'] >= 1;

            ans = f? ans + 1 : ans;

            a['A'-'A']-= 3; a['M'-'A']-= 1; a['R'-'A']-= 2;
            a['G'-'A']-= 1; a['I'-'A']-= 1; a['T'-'A']-= 1;
        }

        cout << ans << "\n";
    }
    return 0;
}
