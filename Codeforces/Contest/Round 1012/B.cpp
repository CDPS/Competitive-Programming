#include <bits/stdc++.h>

using namespace std;

int n, m;
string a[50];

int r[50][50];
int c[50][50];

bool solve(){

    memset(r, 0, sizeof r);
    memset(c, 0, sizeof c);

    for(int i=0;i<n;i++)
        r[i][0] = a[i][0] == '1';
    for(int i=0;i<m;i++)
        c[0][i] = a[0][i] == '1';

    for(int i=0;i<n;i++)
        for(int j=1;j< m;j++)
            r[i][j] = (a[i][j]=='1') + r[i][j-1];

    for(int j=0;j< m;j++)
        for(int i=1;i<n;i++)
            c[i][j] = (a[i][j]=='1') + c[i-1][j];

    for(int i=1;i<n;i++)
        for(int j=1;j< m;j++)
            if(a[i][j]=='1'  && (r[i][j] < (j+1) &&  c[i][j]< i+1) )
                return false;

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i=0;i<n;i++)
            cin >> a[i];

        cout << (solve()? "YES" : "NO" ) << "\n";
    }
    return 0;
}
