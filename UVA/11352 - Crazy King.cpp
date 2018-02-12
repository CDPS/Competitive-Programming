#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int n,m;
char     g[100][100];
bool visit[100][100];
int  level[100][100];

int enemieX[8] = {1,-1, 1,-1, 2, 2,-2,-2};
int enemieY[8] = {2, 2,-2,-2, 1,-1, 1,-1};
int   kingX[8] = {1, 1,-1,-1, 1,-1, 0, 0};
int   kingY[8] = {1,-1, 1,-1, 0, 0, 1,-1};

bool isValid(int x, int y){
    return (x >=0 && x< n && y>=0 && y<m );
}

int xs,ys,xe,ye;
int bfs(){

    queue<node> q; q.push(make_pair(xs,ys));
    visit[xs][ys] = 1;
    level[xs][ys]=0;

    while(!q.empty()){

        node u = q.front(); q.pop();

        if(u.first == xe && u.second == ye) return level[xe][ye];

        for(int i=0;i<8;i++){
            int vx = u.first  + kingX[i];
            int vy = u.second + kingY[i];
            if(isValid(vx,vy) && !visit[vx][vy]){
                visit[vx][vy] = 1; level[vx][vy] = 1 + level[u.first][u.second];
                q.push(make_pair(vx,vy));
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

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                visit[i][j]=0;
                if(g[i][j]=='A') xs = i, ys =j;
                if(g[i][j]=='B') xe = i, ye =j;
            }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='Z'){
                    visit[i][j]=1;
                    for(int k=0;k<8;k++){
                        int vx = i + enemieX[k];
                        int vy = j + enemieY[k];
                        if(isValid(vx, vy) && g[vx][vy]=='.') visit[vx][vy] = 1;
                    }
                }
            }
        }

        int ans = bfs();
        if(ans == -1) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",ans);
    }
    return 0;
}
