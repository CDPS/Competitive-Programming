#include <bits/stdc++.h>

using namespace std;

bool g[51][51];
int visit[51];

int n,m;

void dfs(int x){
    visit[x] = 1;
    for(int i=1;i<=n;i++)
        if( g[x][i] && !visit[i])
            dfs(i);
}

int main(){

    int x, y;
    cin >> n >> m;

    for(int i=0;i<m;i++)
        cin >> x >> y, g[x][y] = g[y][x] =  1;

    int connected = 0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            dfs(i);
            connected++;
        }
    }

    long long ans = pow(2,n-connected);
    cout << ans << "\n";
    return 0;
}
