#include <bits/stdc++.h>

using namespace std;

int m = 20000;

int main(){

    int t,n,x;
    cin >> t;
    string s;

    while(t--){
        cin >> n >> s;

        if(x==0 && s[0]!='S'){ x = m; break;}

        if(x==m && s[0]!='N'){ x = m; break;}

        if(s[0]=='S'){
            if(x+n <= m){ x+=n; }
            else { x = m; break;}
        }

        if(s[0]=='N'){
            if(x-n >=0){x-=n;}
            else { x = m; break;}
        }
    }

    cout << ( (x==0)? "YES" : "NO" ) << "\n";

    return 0;
}
