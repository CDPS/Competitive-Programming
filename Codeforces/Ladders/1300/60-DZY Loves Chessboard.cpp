#include <bits/stdc++.h>

using namespace std;


int visit[100][100];
char    g[100][100];

int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};


typedef pair<int,int> node;

int n,m;

bool isvalid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m)
        if(g[x][y]=='.')return true;
    return false;
}

void bfs(int x,int y){

    visit[x][y]=1;
    g[x][y]='B';

    queue<node> q;
    q.push(make_pair(x,y));

    while(!q.empty()){

        node u = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int vx = u.first + xs[i];
            int vy = u.second + ys[i];

            if(isvalid(vx,vy)){
                if(visit[vx][vy]==0){
                    if(visit[u.first][u.second]==1){
                        visit[vx][vy]=2;
                        g[vx][vy]='W';
                    }else{
                        visit[vx][vy]=1;
                        g[vx][vy]='B';
                    }
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
}

int main(){

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf(" %c",&g[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(visit[i][j]==0 && g[i][j]=='.') bfs(i,j);

   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%c",g[i][j]);
        printf("\n");
    }
    return 0;
}
