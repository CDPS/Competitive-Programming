#include <bits/stdc++.h>

using namespace std;

int n,m,idx;
vector<int> g[2000];
vector<int> t[2000];
stack <int> s;
int visit[20000];

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

    while(true){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
            break;

        int u,v,ti;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&ti);
            u--; v--;
            if(ti==1){
                g[u].push_back(v);
                t[v].push_back(u);
            }
            else{
                g[u].push_back(v);
                g[v].push_back(u);

                t[u].push_back(v);
                t[v].push_back(u);
            }
        }

        kosaraju();

        if(idx==1){
            printf("1\n");
        }else{
            printf("0\n");
        }
         for(int i=0;i<n;i++){
            g[i].clear();
            t[i].clear();
        }
    }
    return 0;
}
