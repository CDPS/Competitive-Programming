#include <bits/stdc++.h>

using namespace std;

int   a[1001][1001];
int row[1001];
int col[1001];
char op;
int n, m, k, x, y;

void solve(){

    cin >> n >> m >> k ;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];

    for(int i=1;i<=n;i++) row[i] = i;
    for(int i=1;i<=m;i++) col[i] = i;

    while(k--){
        cin >> op >> x >> y;
        if(op == 'c')
            swap(col[x], col[y]);
        if(op == 'r')
            swap(row[x], row[y]);
        if(op == 'g')
            cout << a[row[x]][col[y]] << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
