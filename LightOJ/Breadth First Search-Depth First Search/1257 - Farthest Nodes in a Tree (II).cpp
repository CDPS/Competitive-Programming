#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

vector<node> g[30000];
int visit[30000];

int dis1[30000];
int dis2[30000];

map<int,int> mp;

int dfs(int u,int id){
   visit[u]=1;
   for(int i=0;i<g[u].size();i++){
        int v=g[u][i].second;
        if(!visit[v]){
            if(id==1){
                dis1[v]= dis1[u]+g[u][i].first;
                mp[dis1[v]]= v;
            }
            else{
                dis2[v]= dis2[u]+g[u][i].first;
                mp[dis2[v]]= v;
            }
            dfs(v,id);
        }
   }
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        int u,v,w;
        visit[0]=1;

        for(int i=0;i<n-1;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(make_pair(w,v));
            g[v].push_back(make_pair(w,u));
            visit[i+1]=0;
        }

        dis1[0]=0;
        dfs(0,1);
        map<int,int>::reverse_iterator it=mp.rbegin();
        for(int i=0;i<n;i++)
            visit[i]=0;

        int s = it->second;
        mp.clear();
        dis2[s]=0;
        dfs(s,2);

        it=mp.rbegin();
        for(int i=0;i<n;i++)
            visit[i]=0;

        s = it->second;
        mp.clear();

        dis1[s]=0;
        dfs(s,1);

        printf("Case %d:\n",caseno++);
        for(int i=0;i<n;i++)
            printf("%d\n",max(dis1[i],dis2[i]) );


        for(int i=0;i<n;i++)
            g[i].clear();
        mp.clear();
    }
    return 0;
}
