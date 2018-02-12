#include <bits/stdc++.h>

using namespace std;

char     g[300][300];
bool visit[300][300][3];

int xss[4] = {1,-1,0,0};
int yss[4] = {0,0,1,-1};

int n,m;

int xs,ys,xe,ye;

struct node{
    int x,y,state,level;
    node(int a,int b,int c,int d):x(a),y(b),state(c),level(d){}
};

int ad(int state, int factor){
    return (state + 1)*factor;
}

bool isvalid(int x,int y){
    return (x>=0 && x<n && y>=0 && y<m );
}

bool canStep(int xi,int yi, int xf, int yf, int st){
    if(st){
        for(int i= min(yi,yf) ; i<= max(yi,yf);i++)
                if(g[xi][i]=='#') return false;
    }else{
        for(int i= min(xi,xf) ; i<= max(xi,xf);i++)
            if(g[i][yi]=='#') return false;
    }
    return true;
}

int bfs(){

    queue<node> q; q.push(node(xs,ys,0,0));

    while(!q.empty()){

        node u = q.front(); q.pop();
        if(u.x == xe && u.y == ye) return u.level;

        for(int i=0;i<4;i++){
            int vx = (u.x) + ad(u.state,xss[i]);
            int vy = (u.y) + ad(u.state,yss[i]);
            int next = (u.state+1)%3;
            if(isvalid(vx,vy) && canStep(u.x,u.y,vx,vy,i>1) && !visit[vx][vy][next]){
                visit[vx][vy][ next ] = 1;
                q.push(node(vx,vy, next, u.level + 1 ));
            }
        }
    }
    return -1;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                visit[i][j][0] = visit[i][j][1] = visit[i][j][2] = 0;
                if(g[i][j]=='S') xs = i, ys = j;
                if(g[i][j]=='E') xe = i, ye = j;
            }
        }
        int ans = bfs();
        if(ans==-1) printf("NO\n");
        else printf("%d\n",ans);
    }
    return 0;
}
