#include <bits/stdc++.h>

using namespace std;

int        g[25][25];
int n,m,res;

map< pair<int,int> , pair<int,int> > mp;

bool isValid(int x , int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void backTrack(int x, int y, int sx, int sy){

    bool f1=1,f2=1;
    int vx = x+sx , vy = y+sy ;

    if(isValid(vx,vy) && !g[vx][vy] ){
        g[vx][vy]=1; f1=0;
        backTrack(vx,vy,sx,sy);
        g[vx][vy]=0;
    }

    int sxp = mp[make_pair(sx,sy)].first; int syp = mp[make_pair(sx,sy)].second;
    vx = x + sxp; vy= y + syp;

    if(isValid(vx,vy) && !g[vx][vy]){
        g[vx][vy]=1; f2=0;
        backTrack(vx,vy,sxp,syp);
        g[vx][vy]=0;
    }

    res = (f1 && f2)? res +1: res;
}

void setGrid(int n,int m){
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            g[i][j]==0;
}

int main(){

    mp[ make_pair( 1,0) ] =  make_pair(0,1);
    mp[ make_pair(-1,0) ] =  make_pair(0,-1);
    mp[ make_pair( 0,1) ] =  make_pair(-1,0);
    mp[ make_pair( 0,-1)] =  make_pair(1,0);

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        res=0; setGrid(n,m);
        g[0][0]=1;
        backTrack(0,0,1,0);
        printf("%lld\n", res);
    }
    return 0;
}
