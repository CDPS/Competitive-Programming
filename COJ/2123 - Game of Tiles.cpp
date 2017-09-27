#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;


char   g[50][50];
int visit[50][50];
int color[50][50];
int nodes[50][50];

int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};

int n,m,b,ne,c;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mc, VI &seen) {
      for (int j = 0; j < w[i].size(); j++) {
        if (!seen[ w[i][j] ]) {
          seen[ w[i][j] ] = true;
          if (mc[ w[i][j] ] < 0 || FindMatch(mc[ w[i][j] ], w, mc, seen)) {
            mc[w[i][j] ] = i;
            return true;
          }
        }
      }
      return false;
}

int BipartiteMatching(const VVI &w) {
      VI mc = VI(ne, -1);
      int ct = 0;
      for (int i = 0; i < b; i++) {
        VI seen(ne);
        if (FindMatch(i, w,mc, seen)) ct++;
      }
      return ct;
}

bool isvalid(int x,int y ){
    if(x>=0 && x < n && y>=0 && y<m){
        if(g[x][y]=='.'){
            return true;
        }
    }
    return false;
}

int bfs(int x,int y,VVI &w){

    int res=1;
    queue<node> q;
    q.push(make_pair(x,y));
    visit[x][y]=1; color[x][y]=1; nodes[x][y]=b+1;
    b++;

    while(!q.empty()){

       node u = q.front();
       q.pop();

       for(int i=0;i<4;i++){
            int vx = u.first +  xs[i];
            int vy = u.second + ys[i];

            if(isvalid(vx,vy)){
                if(!visit[vx][vy]){
                    res++;
                    if(color[u.first][u.second]==1){
                        ne++;
                        nodes[vx][vy]=ne; color[vx][vy]=2;
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[ub].push_back(vb);
                    }else{
                        b++;
                        nodes[vx][vy]=b;  color[vx][vy]=1;
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[vb].push_back(ub);
                    }
                    visit[vx][vy]=1;
                    q.push(make_pair(vx,vy));

             }else{
                    if(color[u.first][u.second]==1){
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[ub].push_back(vb);
                    }else{
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[vb].push_back(ub);
                    }
                }
            }
       }
    }
    return res;
}

int main(){

    while(scanf("%d %d",&n,&m)==2){

        int ca=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j]=='.') ca++;

                visit[i][j]=0;
                color[i][j]=0;
                nodes[i][j]=0;
            }
        }

        bool flag=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

               if(!visit[i][j] && g[i][j]=='.'){
                    ne=0; b=0;
                    VVI w(ca,VI());
                    c = bfs(i,j,w);

                   for(int i=0;i<b;i++){
                        sort( w[i].begin(), w[i].end() );
                        w[i].erase( unique( w[i].begin(), w[i].end() ), w[i].end() );
                   }

                    int res = BipartiteMatching(w);
                    if((2*res)!=c){
                        flag= true;
                        break;
                    }
               }
            }
            if(flag)
                break;
        }

        if(flag)
            printf("1\n");
        else
            printf("2\n");

    }
    return 0;
}


