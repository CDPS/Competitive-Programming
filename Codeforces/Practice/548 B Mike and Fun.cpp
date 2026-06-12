#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int,int>

int t = 1, n, m, q;

bool  g[501][501];
int row[501];


int get(int x){

    int ans = 0;
    for(int i= 1, curr = 0; i <= m ; i++){
        if(g[x][i] == 1)
            curr++, ans = max(ans, curr);
        else
            curr = 0;
    }

    return ans;
}

int  x, y;

void solve(){


    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];

    priority_queue<pii> pq;
    for(int i = 1; i <= n; i++){
        row[i] = get(i);
        pq.push({row[i], i});
    }

    while(q--){

        cin >> x >> y;

        g[x][y] ^= 1;
        row[x] = get(x);

        pq.push( {row[x], x});
        while(pq.top().f > row[pq.top().s])
            pq.pop();

        cout << pq.top().f << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
