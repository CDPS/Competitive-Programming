#include <bits/stdc++.h>

using namespace std;

vector<int>  g[1000];
int      level[1000];
bool     visit[1000];

int n,m;
void bfs(){

    for(int i=0;i<n;i++) visit[i]=0;
    level[0]=0; visit[0]=1;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int u =  q.front(); q.pop();
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(!visit[v]){
                level[v] = 1 + level[u];
                visit[v] = 1;
                q.push(v);
            }
        }
    }

    g[0].clear();
    for(int i=1;i<n;i++){
        printf("%d\n",level[i]);
        g[i].clear();
    }
}

int main(){

    int t,u,v;
    scanf("%d",&t);

    bool first = true;
    while(t--){
        scanf("%d %d",&n,&m);

        if(!first) printf("\n");
        first = false;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs();
    }
    return 0;
}
