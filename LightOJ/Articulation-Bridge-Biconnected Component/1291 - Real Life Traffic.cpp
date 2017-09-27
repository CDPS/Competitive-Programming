#include <bits/stdc++.h>

using namespace std;

#define MAXNODES 10001

vector <int> g[MAXNODES];

int  visit[MAXNODES];
int    low[MAXNODES];
int   dist[MAXNODES];
int parent[MAXNODES];

map<int, map<int, int> > br;
vector< pair<int, int> > br2;

int n,m,level;

int findset(int u) {
     if(u == parent[u]) return u;
    else return parent[u] = findset(parent[u]);
}

void unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a<b) swap(a,b);
    parent[b] = a;
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
                br[u][v]=1;  br[v][u]=1;
                br2.push_back(make_pair(u,v));
            }
        }else if(parent[u]!=v){
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
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            visit[i]= low[i]= dist[i]=0;
            parent[i]=-1;
        }

        level=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }

        for(int i=0;i<n;i++){
             parent[i]=i;
             dist[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                int v=g[i][j];
                if(br[i][v] !=1){
                    unionset(i,v);
                }
            }
        }

        for(int i=0;i<br2.size();i++){
            int u = findset(br2[i].first);
            int v = findset(br2[i].second);

            dist[u]++;
            dist[v]++;
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(dist[i]==1)
                res++;
        }

        printf("Case %d: %d\n",caseno++,(res+1)/2);

        for(int i=0;i<n;i++){
            g[i].clear();
        }

        br2.clear();
        br.clear();
    }
    return 0;
}
