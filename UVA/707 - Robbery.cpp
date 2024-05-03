#include <bits/stdc++.h>

using namespace std;

int g[101][101][101];

int n,m,t,q;
int xs[5] = {1,-1,0,0,0};
int ys[5] = {0,0,1,-1,0};

vector<pair<int,int>> path[101];

bool isValid(int x, int y, int cur){
    return x >= 1 && x <=n && y >=1 && y <=m && g[x][y][cur] != 1;
}

int dfs(int x, int y, int cur){

    if(g[x][y][cur]>1) return g[x][y][cur];
    if(cur == 1) {
        path[cur].push_back(make_pair(x,y));
        return g[x][y][cur] = 2;
    }

    bool flag = 0 ;
    for(int i=0;i<5;i++){
        int vx = x + xs[i], vy = y + ys[i];
        if(isValid(vx,vy, cur - 1))
            flag |= dfs(vx,vy, cur - 1) == 2;
    }
    if(flag)
        path[cur].push_back(make_pair(x,y));
    return g[x][y][cur] = flag? 2 : 3;
}

int main(){


    int x,x1,x2,y1,y2, caseno = 1;

    while(cin >> m >> n >> t){

        if(n == 0 && m == 0 && t == 0)
            break;

        for(int i=0;i<=t;i++) path[i].clear();

        memset(g, 0, sizeof(g));

        cin >> q;

        while(q--){
            cin >> x >> x1 >> y1 >> x2 >> y2;
            for(int i=y1;i<=y2;i++)
                for(int j=x1;j<=x2;j++)
                    g[i][j][x] = 1;
        }

        int ans = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(g[i][j][t]==0)
                    dfs(i, j, t);

        cout << "Robbery #" << caseno++ << ":" << "\n";
        if(path[1].size() == 0){
            cout << "The robber has escaped." << "\n";
        }else if(path[1].size() == 1){
            for(int time = 1;time <= t; time++){
                if(path[time].size() == 1)
                    cout << "Time step " << time << ": The robber has been at " << path[time][0].second << "," << path[time][0].first << "." << "\n";
            }
        }else{
            cout << "Nothing known." << "\n";
        }
        cout << "\n";
    }
    return 0;
}
