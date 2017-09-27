#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> node;
 
 
char   g[20][20];
int visit[20][20];
int color[20][20];
int nodes[20][20];
 
int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};
 
int n,m,b,ne;
 
typedef vector<int> VI;
typedef vector<VI> VVI;
 
 
 
bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}
 
int BipartiteMatching(const VVI &w) {
  VI mr = VI(w.size(), -1);
  VI mc = VI(w[0].size(), -1);
 
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
 
bool isvalid(int x,int y ){
    if(x>=0 && x < n && y>=0 && y<m){
        if(g[x][y]=='*'){
            return true;
        }
    }
    return false;
}
 
void bfs(int x,int y,VVI &w){
 
    queue<node> q;
    q.push(make_pair(x,y));
    visit[x][y]=1;
    color[x][y]=1;
    nodes[x][y]=b+1;
    b++;
 
    while(!q.empty()){
 
       node u = q.front();
       q.pop();
 
       for(int i=0;i<4;i++){
            int vx = u.first +  xs[i];
            int vy = u.second + ys[i];
 
            if(isvalid(vx,vy)){
                if(!visit[vx][vy]){
                    if(color[u.first][u.second]==1){
                        ne++;
                        nodes[vx][vy]=ne; color[vx][vy]=2;
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[ub][vb]=1;
                    }else{
                        b++;
                        nodes[vx][vy]=b;  color[vx][vy]=1;
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[vb][ub]=1;
                    }
                    visit[vx][vy]=1;
                    q.push(make_pair(vx,vy));
 
             }else{
                    if(color[u.first][u.second]==1){
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[ub][vb]=1;
                    }else{
                        int ub= nodes[u.first][u.second] -1; int vb= nodes[vx][vy]-1;
                        w[vb][ub]=1;
                    }
                }
            }
       }
    }
}
 
int main(){
 
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
 
        scanf("%d %d",&n,&m);
 
        int c=0;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j]=='*')
                    c++;
                visit[i][j]=0;
                color[i][j]=0;
                nodes[i][j]=0;
            }
        }
 
        ne=0; b=0;
        VVI w(c,VI(c,0));
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(!visit[i][j] && g[i][j]=='*' ){
                    bfs(i,j,w);
               }
            }
        }
 
        int res = BipartiteMatching(w);
        printf("Case %d: %d\n",caseno++,res+(c-(res*2)));
    }
    return 0;
}
