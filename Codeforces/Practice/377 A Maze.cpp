#include <bits/stdc++.h>

using namespace std;

int n, m, k, f = 0;
string g[500];

int  xs[4] = {1,-1,0,0};
int  ys[4] = {0,0,1,-1};
bool vs[500][500];


struct edge{
    int x, y, level;
    edge(int x, int y, int level) : x(x), y(y), level(level){}
};

bool isValid(int x, int y){
    return x >= 0 && x< n && y >=0 && y<m && g[x][y] == '.' && !vs[x][y];
}

void bfs(int x, int y){

    queue<edge> q;
    vs[x][y] = true;

    int curr = 1;
    q.push(edge(x,y, curr));

    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int vx = u.x + xs[i];
            int vy = u.y + ys[i];
            if(isValid(vx, vy) && curr + 1 <= f-k)
                q.push(edge(vx, vy, ++curr)), vs[vx][vy] = true;
        }
    }
}

void solve(){

    cin >> n >> m >> k;
    for(int i=0;i<n; i++) cin >> g[i];

    int x, y;
    for(int i=0;i<n; i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='.')
                f++, x  = i, y =j;

    bfs(x, y);
    for(int i=0;i<n; i++){
        for(int j=0;j<m;j++)
            if(g[i][j] == '.' && !vs[i][j])
                g[i][j] = 'X';
        cout << g[i] << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
