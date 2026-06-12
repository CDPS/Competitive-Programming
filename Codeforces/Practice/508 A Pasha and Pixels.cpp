#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m, k, x, y;
bool a[1001][1001];

bool check(int i, int j){
    return i >=1 && i<=n && j>=1 && j<=m && a[i][j];
}

int solve(){

    cin >> n >> m >> k;

    vector<pair<int, int>> v(k+1);
    for(int i=1;i<=k;i++)
        cin >> x >> y, v[i] = {x, y};

    for(int i=1;i<=k;i++){

        x = v[i].first;
        y = v[i].second;

        a[x][y]  = true;

        if( check(x-1, y) && check(x, y-1) && check(x-1, y-1) )
            return i;
        if( check(x+1, y) && check(x, y+1) && check(x+1, y+1) )
            return i;
        if( check(x+1, y) && check(x, y-1) && check(x+1, y-1) )
            return i;
        if( check(x-1, y) && check(x, y+1) && check(x-1, y+1) )
            return i;
    }

    return 0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

