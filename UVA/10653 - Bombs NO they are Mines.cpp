#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int level[1000][1000];
int visit[1000][1000];
int xss[4] = {1,-1,0,0};
int yss[4] = {0,0,1,-1};

int n,m;

bool isvalid(int x, int y){
    return x >=0 && x < n && y>= 0 && y<m;
}

int bfs(int xs,int ys,int xe,int ye){

    level[xs][ys] =0;
    visit[xs][ys] =1;

    queue<node> q; q.push(make_pair(xs,ys));

    while(!q.empty()){

        node  u = q.front(); q.pop();
        if(u.first == xe && u.second == ye) return level[u.first][u.second];

        for(int i=0;i<4;i++){
            int vx = u.first  + xss[i];
            int vy = u.second + yss[i];

            if(isvalid(vx,vy) && !visit[vx][vy]){
                visit[vx][vy] = 1; level[vx][vy] = 1 +level[u.first][u.second];
                q.push(make_pair(vx,vy));
            }
        }
    }
    return -1;
}

int main(){

    int r,u,c,aux,xs,ys,xe,ye;
    while(scanf("%d %d",&n,&m) && !(n==0 && m==0)){

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) visit[i][j]=0;

        scanf("%d",&r);
        for(int i=0;i<r;i++){
            scanf("%d %d",&u,&c);
            for(int j=0;j<c;j++){
                scanf("%d",&aux);
                visit[u][aux] = 1;
            }
        }
        scanf("%d %d",&xs,&ys);
        scanf("%d %d",&xe,&ye);
        printf("%d\n",bfs(xs,ys,xe,ye));
    }
    return 0;
}
