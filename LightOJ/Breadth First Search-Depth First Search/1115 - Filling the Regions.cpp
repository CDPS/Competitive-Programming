#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> node;

int n,m;
char g [52][52];
char t [52][52];

vector< vector<int> > v;
vector< vector<int> > u;

int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};

bool isvalid(int x,int y){
    if(x>=0 && x<n+2 && y>=0 && y<m+2)
            return true;
    return false;
}

void bfs1(int x,int y,char c){
    queue<node> q;
    q.push(make_pair(x,y));
    v[x][y]=1;
    while(!q.empty()){
        node u = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int vx = u.first  + xs[i];
            int vy = u.second + ys[i];
            if(isvalid(vx,vy)){
                if(g[vx][vy]!=c && !v[vx][vy]){
                    v[vx][vy]=1;
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
}

void bfs2(int x,int y,char c){
    queue<node> q;
    q.push(make_pair(x,y));
    v[x][y]=1;
    u[x][y]=1;
    t[x][y]=c;

    while(!q.empty()){
        node us = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int vx = us.first  + xs[i];
            int vy = us.second + ys[i];
            if(isvalid(vx,vy)){
                if(!v[vx][vy] && !u[vx][vy]){
                    v[vx][vy]=1; u[vx][vy]=1;
                    t[vx][vy]=c;
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
}
int main(){

    int tests,caseno=1;

    scanf("%d",&tests);

    while(tests--){
        scanf("%d %d",&n,&m);

        for(int i=0;i<n+2;i++){
            for(int j=0;j<m+2;j++){
                t[i][j]= g[i][j]='.';
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&g[i][j]);
            }
        }

        u= vector< vector<int> >(n+2,vector<int>(m+2,0));
        for(int i=0;i<n+2;i++){
            for(int j=0;j<m+2;j++){
                if(!u[i][j]&& g[i][j]!='.'){
                    v = vector< vector<int> >(n+2,vector<int>(m+2,0));
                    bfs1(0,0,g[i][j]);
                    bfs2(i,j,g[i][j]);
                }
            }
        }

        printf("Case %d:\n",caseno++);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                    printf("%c",t[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
