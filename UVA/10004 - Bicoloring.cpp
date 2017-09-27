#include <bits/stdc++.h>

using namespace std;

vector<int>  g[200];

int visit[200],color[200];
int n,m;

bool dfs(int u){
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(!visit[v]){
            visit[v]=1; color[v]=~color[u];
            if(!dfs(v))
                return false;
        }else if(color[u]==color[v]){
                return false;
        }
    }
    return true;
}

int main(){


    int u,v;

    while(scanf("%d",&n) && n){
        scanf("%d",&m);

        memset(visit,0,sizeof visit);
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v); g[v].push_back(u);
        }

        if(!dfs(0))
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");

        for(int i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
