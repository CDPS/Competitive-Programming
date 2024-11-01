#include <bits/stdc++.h>

using namespace std;

int a[1000][26];
int b[26];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;
    int idx = 0;
    char c;

    while(cin >> s && s[0]!='#'){
        for(int i=0;i<s.size();i++)
            a[idx][s[i]-'a']++;
        idx++;
    }

    cin.ignore();
    while(getline(cin,s) && s[0]!='#'){
        stringstream ss;
        ss << s;
        memset(b, 0, sizeof b);
        while(ss >> c) b[c-'a']++;

        int ans=0;
        for(int i=0;i<idx;i++){
            bool f = true;
            for(int j=0;j<26;j++)
                f &= a[i][j] <= b[j];
            if(f)ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
