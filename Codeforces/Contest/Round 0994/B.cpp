#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n; string s;
    cin >> t;

    while(t--){

        cin >> n >> s;

        if(s[0]  == 's') s[0] = '.';
        if(s[n-1]== 'p') s[n-1] = '.';

        string allp, alls, acc, sempty = "";
        for(int i=0;i<n;i++)
            if(s[i]!='.')
                acc+=s[i], allp+='p', alls+='s';

        if(acc == sempty || acc == allp || acc == alls )
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}

