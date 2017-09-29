#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int> g[10000];
vector<int> t[10000];

vector<int> tps;
stack<int> s;

int visit[10000];

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
    tps.push_back(u);

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


    tps = vector<int>();

    while(!s.empty()){
        int u = s.top();
        s.pop();

        if(!visit[u]){
            dfst(u);
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
            g[u-1].push_back(v-1);
            t[v-1].push_back(u-1);
        }

        kosaraju();


        for(int i=0;i<n;i++){
              g[i].clear();
              t[i].clear();
        }
        s = stack<int>();
	return 0;
}
