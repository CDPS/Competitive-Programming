#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int, int>

const int oo = 1e9;

int t = 1, n, m;

string g[1000];
int level[1000][1000];
int xs[4] = {1, -1, 0, 0};
int ys[4] = {0, 0, 1, -1};

bool isValid(int x, int y){
    return x >=0 && x< n && y >=0 && y < m && g[x][y]!= 'T';
}

void bfs(int x, int y){

    queue< pii > q;

    q.push({x, y});
    level[x][y] = 0;

    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(int i=0; i< 4; i++){
            int vx = u.f + xs[i];
            int vy = u.s + ys[i];
            if(isValid(vx, vy) &&  level[u.f][u.s] + 1 < level[vx][vy] ){
                level[vx][vy] = level[u.f][u.s] + 1;
                q.push({vx, vy});
            }
        }
    }
}

int solve(){

    cin >> n >> m;

    int tx = 0, ty = 0, sx = 0, sy=0;
    for(int i=0;i < n; i++) {
        cin >> g[i];
        for(int j=0; j<m;j++){
            if(g[i][j] == 'E') tx = i, ty = j;
            if(g[i][j] == 'S') sx = i, sy = j;
            level[i][j] = oo;
        }
    }

    bfs(tx, ty);

    int ans = 0;
    for(int i=0;i < n; i++)
        for(int j=0; j<m;j++)
            if(g[i][j] >= '1' && g[i][j] <= '9')
                ans+= (level[i][j] <= level[sx][sy])*(g[i][j] - '0');
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
