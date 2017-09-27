#include <bits/stdc++.h>

using namespace std;

vector <int> g[10006];
vector < pair<int,int> > bridges;

int  visit[10006];
int    low[10006];
int   dist[10006];
int parent[10006];


int n,m,level;

void dfs(int u){

    level++;
    visit[u]=1;
    dist[u]=level;
    low[u]=level;

    for(int i=0;i < g[u].size();i++){
        int v =g[u][i];

        if(visit[v]==0){
            parent[v]=u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dist[u] ){
                int a=u,b=v;
                if(a>b){
                    swap(a,b);
                }
              bridges.push_back(make_pair(a,b));
            }
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
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            int u,v;
            scanf("%d (%d)",&u,&m);
            for(int j=0;j<m;j++){
                scanf("%d",&v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }

        level=0;
        for(int i=0;i<n;i++){
            visit[i]=0;
            parent[i]=-1;
        }
        bridges = vector< pair<int,int> >();

        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }

        sort(bridges.begin(),bridges.end());
        printf("Case %d:\n",caseno++);
        printf("%d critical links\n",bridges.size());
        for(int i=0;i<bridges.size();i++){
            printf("%d - %d\n",bridges[i].first,bridges[i].second);
        }

        for(int i=0;i<n;i++){
            g[i].clear();
        }
    }

    return 0;
}
