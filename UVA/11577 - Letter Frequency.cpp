#include <bits/stdc++.h>

using namespace std;

int a[26];

int main(){

    cin.sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    while(t--){

        memset(a, 0, sizeof a);
        string s;
        getline(cin, s);

        int maxi = 0;
        for(int i=0;i<s.size();i++){
          int c = tolower(s[i]);
          if(c>='a' && c<= 'z')
            a[c-'a']++, maxi = max(maxi, a[c-'a']);
        }

        for(int i=0;i<26;i++)
            if(a[i]==maxi) cout << (char)(i+'a');
        cout << "\n";
    }
    return 0;
}
