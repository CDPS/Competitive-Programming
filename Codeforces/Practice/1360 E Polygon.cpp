#include <bits/stdc++.h>

using namespace std;

int t, n;
string g[50];

bool check(){
    for(int i=n-2; i>=0; i--)
        for(int j=n-2; j>=0;j--)
            if(g[i][j]=='1' && g[i+1][j]=='0' && g[i][j+1]=='0' )
                return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> g[i];

        cout << ( check()? "YES" : "NO" )<< "\n";
    }

    return 0;
}
