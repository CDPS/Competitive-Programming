#include <bits/stdc++.h>

using namespace std;

int r,c,k;

string m[1000], p[1000];

bool allok[1000];

bool solve(){
    for(int i=0;i<r;i++)
        for(int j=0;j<k;j++)
            if(p[i][j]=='*' && !allok[i])
                return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> r >> c >> k;

    for(int i=0;i<r;i++)
        cin >> m[i] >> p[i], allok[i]=true;

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            allok[i] &= m[i][j] =='*';

    cout << ( solve() ? "Y" : "N" )<< "\n";
    return 0;
}
