#include <bits/stdc++.h>

using namespace std;

char g[20][20];

int adx[4]={1,-1,0,0};
int ady[4]={0,0,1,-1};
bool v[20][20];


int bfs(int x,int y,int n,int m,char o){

    queue< pair<int,int> > q;
    q.push( make_pair(x,y) ) ;

    v[x][y]=1;
    int res=0;

    if(g[x][y]==o)
        res++;

    while(!q.empty()){

        int ux= q.front().first;
        int uy= q.front().second;
        q.pop();

        for(int i=0;i<4;i++){

            int vx= ux+adx[i];
            int vy= uy+ady[i];

            if( (vx>=0 && vx<n)  && (vy>=0 && vy<m)){

                if(g[vx][vy]==o && !v[vx][vy] ){

                    q.push(make_pair(vx,vy));
                    v[vx][vy]=1;
                    res++;
                }
            }

            if(uy==m-1){

                if(g[ux][0]==o && !v[ux][0] ){
                    q.push(make_pair(ux,0));
                    v[ux][0]=1;
                    res++;
                }
            }
            if(uy==0){
                if(g[ux][m-1]==o && !v[ux][m-1] ){
                    q.push(make_pair(ux,m-1));
                    v[ux][m-1]=1;
                    res++;
                }
            }
        }
    }
    return res;
}

int main(){


    int n,m;

    while(scanf("%d %d",&n,&m)==2){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                v[i][j]=0;
            }
        }

        int x,y;
        scanf("%d %d",&x,&y);
        char o = g[x][y];
        int res = bfs(x,y,n,m,o);

        res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==o && !v[i][j])
                    res=max(res,bfs(i,j,n,m,o));
        printf("%d\n",res);
    }

    return 0;
}
