#include <bits/stdc++.h>

using namespace std;

vector<int> g[20];
bool    visit[20];
int     level[20];

int bfs(int s,int t){

    for(int i=0;i<20;i++) visit[i] = level[i]=0;

    queue<int> q; q.push(s);
    visit[s]=1;

    while(!q.empty()){

        int u = q.front(); q.pop();
        if(u==t) return level[t];

        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(!visit[v])
                visit[v] = 1, level[v]= 1 + level[u],q.push(v);
        }
    }
    return 0;
}

int main(){

    int m,u,v,q,caseno=1;
    while(scanf("%d",&m)==1){

        for(int i=0;i<m;i++)
            scanf("%d",&v), v--,g[0].push_back(v),g[v].push_back(0);

        for(int i=1;i<19;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++)
             scanf("%d",&v), v--,g[i].push_back(v),g[v].push_back(i);
        }

        scanf("%d",&q);
        printf("Test Set #%d\n",caseno++);
        while(q--){
            scanf("%d %d",&u,&v);
            printf("%2d to %2d: %d\n",u,v,bfs(u-1,v-1));
        }

        printf("\n");
        for(int i=0;i<20;i++) g[i].clear();
    }
    return 0;
}
