#include <bits/stdc++.h>

#define node pair<int,int>

using namespace std;

char    g[1002][1002];
int visit[1002][1002];
int n,m;

int xs [8]= {1,-1,0,0, 1,1,-1,-1};
int ys [8]= {0,0,1,-1, 1,-1,1,-1};

vector<node> walls;

int bfs1(){
    int ans =0;
    walls = vector<node>();
    queue<node> q;
    visit[0][0]=1;
    q.push(make_pair(0,0));

    while(!q.empty()){
        node u  = q.front();q.pop();
        for(int i=0;i<8;i++){
            int vx = u.first  + xs[i],vy = u.second + ys[i];
            if(vx >=0 && vx <n+2 && vy>=0 && vy <m+2 && !visit[vx][vy]){
                if(g[vx][vy]!='.'){
                    visit[vx][vy]=1;
                    q.push(make_pair(vx,vy));
                    if(g[vx][vy]=='#') ans++;
                }else{
                    visit[vx][vy]=2;
                    walls.push_back(make_pair(vx,vy));
                }
            }
        }
    }
    return ans;
}

int bfs2(int x,int y){
    int ans =0;
    vector<node> memo;
    queue<node> q; q.push(make_pair(x,y));
    while(!q.empty()){
        node u  = q.front(); q.pop();
        for(int i=0;i<8;i++){
            int vx = u.first  + xs[i],vy = u.second + ys[i];
            if(vx >=0 && vx <n+2 && vy>=0 && vy <m+2 && !visit[vx][vy]){
                if(g[vx][vy]!='*'){
                    visit[vx][vy]=1;
                    q.push(make_pair(vx,vy));
                    memo.push_back(make_pair(vx,vy));
                    if(g[vx][vy]=='#') ans++;
                }
            }
        }
    }
    for(int i=0;i<memo.size();i++){
        int vx = memo[i].first, vy = memo[i].second;
        visit[vx][vy]=0;
    }
    return ans;
}

int main(){

    while(scanf("%d %d",&n,&m)==2){

        for(int i=0;i<m+2;i++) g[0][i]=g[n+1][i]='.',visit[0][i]=visit[n+1][i]=0;

        for(int i=0;i<n+2;i++) g[i][0]=g[i][m+1]='.',visit[i][0]=visit[i][m+1]=0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf(" %c",&g[i][j]),visit[i][j]=0;

        int ans = bfs1();

        int maxi = 0;
        for(int i=0;i<walls.size();i++){
            int vx = walls[i].first; int vy = walls[i].second;
            maxi = max(maxi,bfs2(vx,vy));
        }
        printf("%d\n",ans+maxi);
    }
    return 0;
}
