#include <bits/stdc++.h>

using namespace std;

vector <int> g[10002];

int  visit[10002];
int    low[10002];
int   dist[10002];
int parent[10002];
int sets  [10002];

int n,m,q,level;

int findset(int v) {
    if (sets[v] != -1 && sets[v] != v)
        return sets[v] = findset(sets[v]);
    return v;
}

void unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a<b) swap(a,b);
    sets[b] = a;
}


void dfs(int u){

    visit[u]=1;
    level++;
    dist[u] = low[u] =level;

    for(int i=0;i<g[u].size();i++){
        int v =g[u][i];

        if(!visit[v]){
            parent[v]=u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(low[v]>dist[u]){
                unionset(u,v);
            }
        }else if(parent[u]!=v){
                low[u]= min(low[u],dist[v]);
        }
    }

}

int main(){


    while(true){

        scanf("%d %d %d",&n,&m,&q);

        if(n==0 && m==0 && q==0)
            break;

        int u,v;

        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            visit[i]= low[i]= dist[i]=0;
            parent[i]=-1;
            sets[i]=i;
        }

        level=0;

        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }

        while(q--){
            scanf("%d %d",&u,&v);
            u--;v--;
            if(findset(u)==findset(v))
                printf("Y\n");
            else
                printf("N\n");
        }

        printf("-\n");
        for(int i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
