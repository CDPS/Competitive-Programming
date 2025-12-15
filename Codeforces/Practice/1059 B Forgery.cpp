#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int xs[8] = { 1, -1,  0,  0,  1,  1, -1, -1};
int ys[8] = { 0,  0,  1, -1,  1, -1,  1, -1};

string    g[1000];
string curr[1000];

bool isValid(int x, int y){
    return x >=0 && x<n && y>=0 && y<m && g[x][y]=='#';
}

void process(int i, int j){

    bool allValid = true;
    for(int k=0;k<8;k++)
        allValid &= isValid(i + xs[k], j + ys[k]);
    if(!allValid) return ;

     for(int k=0;k<8;k++)
        curr[i + xs[k] ][j + ys[k] ] = '#';
}

bool solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> g[i], curr [i] = string(m,'.');

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            process(i,j);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(curr[i][j] != g[i][j])
                return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << (solve()?"YES" : "NO" ) << "\n";

    return 0;
}

