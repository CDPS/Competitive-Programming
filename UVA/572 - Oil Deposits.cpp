#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

char g[100][100];
bool v[100][100];
int xs[8]={1,-1,0,0,-1,1,-1,1},ys[8]={0,0,1,-1,1,1,-1,-1};
int n,m;

bool isValid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]=='@')
        return true;
    return false;
}

void bfs(int x, int y){
    queue<node> q;
    q.push(make_pair(x,y));
    v[x][y]=1;
    while(!q.empty()){
        node u = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int vx = u.first  + xs[i];
            int vy = u.second + ys[i];
            if(isValid(vx,vy)&& !v[vx][vy])
                q.push(make_pair(vx,vy)), v[vx][vy]=1;
        }
    }
}

int main(){
    while(scanf("%d %d",&n,&m) && n ){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf(" %c",&g[i][j]), v[i][j]=0;
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(isValid(i,j) && !v[i][j])bfs(i,j),res++;
        printf("%d\n",res);
    }
    return 0;
}
