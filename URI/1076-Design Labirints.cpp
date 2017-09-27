#include <bits/stdc++.h>

using namespace std;

vector<int> g[50];
int visit [50];

int dfs(int s){

    int res = 1;

    for(int i=0;i<g[s].size();i++){
        if(!visit[g[s][i]]){
            visit[ g[s][i]]=1;
            res += dfs(g[s][i]);
        }
    }

    return res;
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int s;
        scanf("%d",&s);

        int n,m;

        scanf("%d %d",&n,&m);

        int u,v;

        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(visit,0,sizeof visit);
        int res = dfs(s)-2;

        printf("%d\n",res*2);

        for(int i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
