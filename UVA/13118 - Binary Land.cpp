#include <bits/stdc++.h>

using namespace std;

int n,m;

string g[40];
bool v[40][40][40][40];

int xs1[4]={1,-1,0,0};
int ys1[4]={0,0,1,-1};

int xs2[4]={1,-1,0,0};
int ys2[4]={0,0,-1,1};

int tx,ty,xs,ys,xt,yt;

struct node{
    int x1,y1,x2,y2,l;
    node( int x1, int y1, int x2,int y2, int l): x1(x1),y1(y1),x2(x2),y2(y2), l(l){}
};

bool finish(node &u){
    return u.x1 == tx && u.x2 == tx && u.y1 == ty && u.y2 == ty;
}

bool isValid(int x, int y){
    return x>=0 && x <n && y>=0 && y<m && g[x][y] == '.';
}

int bfs(){

    queue<node> q;
    q.push( node(xs,ys,xt,yt,0) );
    v[xs][ys][xt][yt] = 1;

    while(!q.empty()){

        node u = q.front();
        q.pop();

        if(finish(u)) return u.l;

        for(int i=0;i<4;i++){

            int vx1 = u.x1 + xs1[i]; int vy1 = u.y1 + ys1[i];

            int vx2 = u.x2 + xs2[i]; int vy2 = u.y2 + ys2[i];

            if(!isValid(vx1,vy1)) vx1 = u.x1, vy1 = u.y1;

            if(!isValid(vx2,vy2)) vx2 = u.x2, vy2 = u.y2;

            if(!v[vx1][vy1][vx2][vy2]){
                v[vx1][vy1][vx2][vy2] = v[vx2][vy2][vx1][vy1] = 1;
                q.push( node(vx1,vy1,vx2,vy2,u.l + 1));
            }
        }
    }
    return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(cin >> n >> m){

        cin >> tx >> ty >> xs >> ys >> xt >> yt;
        tx--; ty--; xs--; ys--; xt--; yt--;

        for(int i=0;i<n;i++) cin >> g[i];

        memset(v,0,sizeof v);

        int ans = bfs();

        if(ans != -1)
            cout << ans << "\n";
        else
            cout << "NO LOVE" << "\n";
    }
    return 0;
}
