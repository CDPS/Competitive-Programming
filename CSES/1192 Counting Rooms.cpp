#include <bits/stdc++.h>

using namespace std;

int n, m;
string g[1000];

bool vs[1000][1000];

int xs[4] = {1, -1, 0,  0};
int ys[4] = {0,  0, 1, -1};


bool isvalid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m && g[x][y]=='.' && !vs[x][y];
}

void bfs(int x, int y){

    queue<pair<int,int>> q;
    q.push({x, y});
    vs[x][y] = true;
    while( !q.empty()){

        auto u = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int vx = u.first  + xs[i];
            int vy = u.second + ys[i];
            if(isvalid(vx,vy))
                vs[vx][vy] = true, q.push({vx, vy});
        }
    }
}
int main(){


    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> g[i];

    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(isvalid(i,j))
                bfs(i,j), ans++;
    cout << ans << "\n";
    return 0;
}
