#include <bits/stdc++.h>

using namespace std;

vector<int> g[10000];

int  visit[10006];
int    low[10006];
int   dist[10006];
int parent[10006];
int     ap[10006];

int n,m,level;

//articulation points for a undirected graph
void dfs(int u){

    level++;
    visit[u]=1;
    dist[u]= low[u]=level;

    int child=0;

    for(int i=0;i < g[u].size();i++){
        int v =g[u][i];
        child++;

        if(visit[v]==0){

            parent[v]=u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if(parent[u]==-1 && child >1)
                 ap[u]=1;

            if(parent[u]!=-1 && low[v]>=dist[u])
                    ap[u]=1;

        }else{
             if(parent[u]!=v)
                low[u]= min(low[u],dist[v]);
        }
    }

}


int main(){


    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        int u,v;

        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int res;
        res = level=0;
        for(int i=0;i<n;i++){
            visit[i]=low[i]=ap[i]=dist[i]=0;
            parent[i]=-1;
        }

        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }

        for(int i=0;i<n;i++){
            if(ap[i])
                res++;
        }

        printf("Case %d: %d\n",caseno++, res);
        for(int i=0;i<n;i++)
            g[i].clear();

    }
    return 0;
}

