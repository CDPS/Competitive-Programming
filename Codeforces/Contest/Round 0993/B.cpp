#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t; string s;
    cin >> t;

    while(t--){
        cin >> s;

        for(int i=s.size()-1; i >=0;i--)
            if(s[i]=='q') cout << 'p';
            else if(s[i]=='p') cout << 'q';
            else cout << 'w';
        cout << "\n";
    }
    return 0;
}

