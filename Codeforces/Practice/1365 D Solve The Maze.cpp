#include <bits/stdc++.h>

using namespace std;

int n, m;
string g[50];

bool vs[50][50];
int xs[4] = {1, -1, 0,  0};
int ys[4] = {0,  0, 1, -1};

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m && g[x][y]!='#' && !vs[x][y];
}

bool isvalid2(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m && g[x][y]=='.';
}

pair<int, int> bfs(int x, int y){

    queue<pair<int,int>> q;
    q.push({x, y});
    vs[x][y] = true;

    if(g[x][y] == '#') return {0,0};

    int good = 0,  bad  = 0;
    while( !q.empty()){

        auto u = q.front(); q.pop();

        if(g[u.first][u.second] == 'G') good++;
        if(g[u.first][u.second] == 'B') bad++;
        for(int i=0;i<4;i++){
            int vx = u.first  + xs[i];
            int vy = u.second + ys[i];
            if(isvalid(vx,vy))
                 vs[vx][vy] = true, q.push({vx, vy});
        }
    }

    return {good, bad};
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> g[i];

        int expected = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 'G')expected++;
                vs[i][j] = false;
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j] == 'B')
                  for(int k=0;k<4;k++)
                    if(isvalid2(i + xs[k], j + ys[k]))
                        g[i + xs[k]][j + ys[k]] = '#';

        auto ans = bfs(n-1, m-1);

        cout << (expected==ans.first && ans.second == 0 ? "YES" : "NO") << "\n";
    }

    return 0;
}

