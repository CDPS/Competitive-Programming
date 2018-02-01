#include <bits/stdc++.h>

using namespace std;

char g[30][30][30];
int  v[30][30][30];
int  d[30][30][30];
int xs[4]= {1,-1,0,0};
int ys[4]= {0,0,1,-1};

int l,n,m;
int ls,ns,ms, le,ne,me;

struct node{
    int x,y,z;
    node(int a,int b,int c): x(a),y(b),z(c){};
};


bool isvalid(int x,int y,int z){
    if(x>=0 && x<n && y>=0 && y<m && z >=0 && z<l)
        return g[z][x][y] != '#';
    return false;
}

int bfs(){

    v[ls][ns][ms]=1;

    queue<node> q;

    q.push(node(ns,ms,ls));

    while(!q.empty()){

        node u = q.front(); q.pop();

        int x = u.x, y = u.y ,z = u.z;

        if(x == ne && y == me && z == le) return d[z][x][y];

        if(isvalid(x,y,z+1) && !v[z+1][x][y]){
            v[z+1][x][y] = 1,d[z+1][x][y] = 1 + d[z][x][y],q.push(node(x,y,z+1));
        }
        if(isvalid(x,y,z-1) && !v[z-1][x][y])
            v[z-1][x][y] = 1,d[z-1][x][y] = 1 + d[z][x][y],q.push(node(x,y,z-1));

        for(int i=0;i<4;i++){
            int vx = x + xs[i];
            int vy = y + ys[i];

            if(isvalid(vx,vy,z) && !v[z][vx][vy]){
                v[z][vx][vy] = 1;
                d[z][vx][vy] = 1 + d[z][x][y];
                q.push(node(vx,vy,z));
            }
        }
    }
    return -1;
}
int main(){

    while(scanf("%d %d %d",&l,&n,&m) && !(l==0 && n==0 && m==0)){

        for(int i=0;i<l;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<m;k++){
                    scanf(" %c",&g[i][j][k]), v[i][j][k]= d[i][j][k]=0;
                    if(g[i][j][k]=='S') ls = i, ns=j, ms = k;
                    if(g[i][j][k]=='E') le = i, ne=j, me = k;
                }


        int ans = bfs();
        if(ans == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
