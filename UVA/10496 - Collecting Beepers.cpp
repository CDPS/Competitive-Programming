#include <bits/stdc++.h>

using namespace std;

int t,xs,ys,xl,yl,n,m;
bool visit[10];

struct point{
    int x,y;
    point(int a,int b){ x=a; y = b; }

}; vector<point> g;

int dis(int x1,int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2) ;
}

int res;
void backtrack(int x, int acc){

    if(x==n){
        int resp= acc + dis(xs,ys,xl,yl);
        res= min(res,resp);
        return;
    }
    for(int i=0;i<g.size();i++){
        if(!visit[i]){

            visit[i]=1;
            int d = dis(xl,yl,g[i].x,g[i].y), auxx=xl, auxy=yl;
            xl = g[i].x;  yl = g[i].y;

            backtrack(x+1,acc+ d);

            visit[i]=0; xl= auxx; yl=auxy;
        }
    }
}

int main(){
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        scanf("%d %d",&xs,&ys);
        scanf("%d",&n);

        memset(visit,0, n);

        for(int i=0;i<n;i++){
            scanf("%d %d",&xl,&yl);
            g.push_back(point(xl,yl));
        }

        res=1000;
        xl=xs; yl=ys;
        backtrack(0,0);
        printf("The shortest path has length %d\n",res);
        g.clear();
    }
    return 0;
}
