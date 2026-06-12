#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

string g[50];
int color[50][50];
int xs[4] = {1,-1,0,0};
int ys[4] = {0,0,1,-1};

bool isValid(int x, int y, char c){
    return x >=0 && x<n && y>=0 && y < m && g[x][y] == c;
}

bool dfs(int x, int y, int px, int py, char c){

    color[x][y] = 1;
    for(int i=0;i< 4;i++){
        int vx = x + xs[i], vy = y + ys[i];
        if(isValid(vx, vy,c) &&!(vx == px && vy == py)){
            if(color[vx][vy] == 1)
                return true;
            if(color[vx][vy] == 0 && dfs(vx, vy, x, y, c))
               return true;
        }
    }
    color[x][y] = 2;
    return false;
}

bool solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> g[i];

    bool ans = false;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(color[i][j]== 0)
                ans|= dfs(i, j, -1, -1, g[i][j]);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << (solve()? "Yes" : "No") << "\n" ;

    return 0;
}
