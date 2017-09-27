#include <bits/stdc++.h>

using namespace std;

int n,m,idx;

vector<int> g[20000];
vector<int> t[20000];

stack <int> s;

int visit[20000];
int comp [20000];
int out  [20000];
int in   [20000];

void dfs(int u){
    visit[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(!visit[v])
            dfs(v);
    }
    s.push(u);
}

void dfst(int u){
    comp[u]=idx;
    visit[u]=1;
    for(int i=0;i<t[u].size();i++){
        int v= t[u][i];
        if(!visit[v])
            dfst(v);
    }
}


void kosaraju(){

   for(int i=0;i<n;i++)
        visit[i]=0;

    for(int i=0;i<n;i++)
        if(!visit[i])
            dfs(i);

   for(int i=0;i<n;i++)
        visit[i]=0;

    idx=0;
    while(!s.empty()){
        int u = s.top();
        s.pop();

        if(!visit[u]){
            dfst(u);
            idx++;
        }
    }
}

int main(){

    int test,caseno=1;

    scanf("%d",&test);

    while(test--){
        scanf("%d %d",&n,&m);

        int u,v;

        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            u--; v--;
            g[u].push_back(v);
            t[v].push_back(u);
        }

        kosaraju();

        for(int i=0;i<idx;i++){
            in[i]=0;
            out[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                if(comp[i]!=comp[g[i][j]]){
                    out[ comp[i] ] ++;
                    in[ comp[g[i][j]] ]++;
                }
            }
        }

        if(idx==1)
            printf("Case %d: 0\n",caseno++);
        else{

            int inm=0,outm=0;
            for(int i=0;i<idx;i++){
                if(!out[i]) outm++;
                if(!in[i])   inm++;
            }

            printf("Case %d: %d\n",caseno++, max(inm,outm) );
        }

        for(int i=0;i<n;i++){
            g[i].clear();
            t[i].clear();
        }
    }
    return 0;
}
