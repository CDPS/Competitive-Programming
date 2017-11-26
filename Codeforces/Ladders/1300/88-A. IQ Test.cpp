#include <bits/stdc++.h>

using namespace std;

char g[4][4];

bool check(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(g[i][j]==g[i][j+1]&&g[i][j]==g[i+1][j]&&g[i][j]==g[i+1][j+1])
                return true;
    return false;
}

int main(){

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> g[i][j];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            g[i][j]= (g[i][j]=='.'? '#':'.' );
            if(check()){ cout << "YES\n"; return 0; }
            g[i][j]= (g[i][j]=='.'? '#':'.' );
        }
    }
    cout << "NO\n";
    return 0;
}
