#include <bits/stdc++.h>

using namespace std;

int w  [1000];
int g  [1000][1000];
int acc[1000];
int n,m;

struct edge{
    int w,idx;

    edge(int a, int b){
          w = a;
        idx = b;
    }
    bool operator < (const edge &a) const{
        return w < a.w;
    }
};

priority_queue<edge> pq;

int main(){

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d",w+i),acc[i]=0,pq.push(edge(w[i],i));

    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        u--;v--;
        g[u][v]= g[v][u]=1;
        acc[u] = acc[u] + w[v];
        acc[v] = acc[v] + w[u];
    }

    int ans =0;

    while(!pq.empty()){
        edge x = pq.top();pq.pop();
        u = x.idx, ans = ans + acc[u];
        acc[u]=0;
        for(int i=0;i<n;i++) if(g[u][i]) g[u][i]=g[i][u]=0,acc[i] = acc[i] - x.w;
    }
    printf("%d\n",ans);
    return 0;
}
