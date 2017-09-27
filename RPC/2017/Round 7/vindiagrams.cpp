#include <bits/stdc++.h>

using namespace std;

char g[102][102];
int n,m;

struct state{
    int x,y,d;
    state(int a,int b, int c){
        x= a; y=b; d=c;
    }
};

bool isValid(int x, int y){
    if(x>=0 && x< n+2 && y>=0&& y<m+2)
        return true;
    return false;
}

bool isIntersection(int x, int y){
    if(g[x-1][y]=='X' && g[x+1][y]=='X' && g[x][y-1]=='X' && g[x][y-1]=='X')
        return true;
    return false;
}

int xs[4]={0,0,1,-1};
int ys[4]={1,-1,0,0};
bool v[102][102];

void bfs(int x, int y){

    v[x][y]=1;
    queue<state> q;q.push(state(x,y,0));

    while(!q.empty()){
        state u = q.front();q.pop();

        bool inter = isIntersection(u.x,u.y);

        for(int i=0;i<4;i++){
            int vx = u.x + xs[i],vy = u.y + ys[i];

            if(isValid(vx,vy) && !v[vx][vy] && g[vx][vy]!='.'){
                if(inter){
                    if(u.d==0 && i<=1){ q.push(state(vx,vy,0)); v[vx][vy]=1;}
                    if(u.d==1 && i>1){ q.push(state(vx,vy,1)); v[vx][vy]=1;}
                }else{
                     q.push(state(vx,vy,i>1)); v[vx][vy]=1;
                }
            }
        }
    }
}

void bfs2(int x, int y){
    v[x][y]=1;
    queue<state> q; q.push(state(x,y,0));
    while(!q.empty()){
        state u = q.front();q.pop();
        for(int i=0;i<4;i++){
            int vx = u.x + xs[i],vy = u.y + ys[i];
            if(isValid(vx,vy) && !v[vx][vy]){
                q.push(state(vx,vy,0)); v[vx][vy]=1;
            }
        }
    }
}

int t[102][102];
int resin;
int bfs3(int x, int y){
    v[x][y]=1;
    t[x][y]++;
    if(t[x][y]==2)
            resin++;
    int res=1;
    queue<state> q; q.push(state(x,y,0));
    while(!q.empty()){
        state u = q.front();q.pop();
        for(int i=0;i<4;i++){
            int vx = u.x + xs[i],vy = u.y + ys[i];
            if(isValid(vx,vy) && !v[vx][vy]){
                q.push(state(vx,vy,0)); v[vx][vy]=1;
                t[vx][vy]++;
                if(t[vx][vy]==2)
                    resin++;
                if(g[vx][vy]=='.')
                    res++;
            }
        }
    }
    return res;
}

void Set(){
    for(int i=0;i<n+2;i++)
        for(int j=0;j<m+2;j++)
            v[i][j]=0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    int xa,ya, xb,yb,resa,resb;

    for(int i=0;i<n+2;i++)
        for(int j=0;j<m+2;j++)
            g[i][j]='.',v[i][j]=t[i][j]=0;


    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
            if(g[i][j]=='A')
                xa= i, ya=j;

            if(g[i][j]=='B')
                xb= i, yb=j;
        }

    bool f=0;resin=0;
    bfs(xa,ya);
    bfs2(0,0);

    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            if(!v[i][j]){
                resa = bfs3(i,j);f=1;
                break;
            }
        }
        if(f)break;
    }

    Set();
    bfs(xb,yb);
    bfs2(0,0);
    f=0;
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            if(!v[i][j]){
                resb = bfs3(i,j);f=1;
                break;
            }
        }
        if(f)break;
    }
    cout << abs(resa-resin) << " " << abs(resb-resin) << " " <<resin << "\n";
    return 0;
}
