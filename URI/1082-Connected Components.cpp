#include <bits/stdc++.h>

using namespace std;


int visit[27];
vector<int> g[27];

int n,m;


void dfs(int u,vector<int> &a){
    visit[u]=1;
    a.push_back(u);
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(!visit[v]){
            dfs(v,a);
        }
    }
}

int main(){
    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);

        char u,v;
        for(int i=0;i<m;i++){
            scanf(" %c %c",&u,&v);
            g[u-97].push_back((int)(v-97));
            g[v-97].push_back((int)(u-97));
        }

        memset(visit,0,sizeof(visit));

        printf("Case #%d:\n",caseno++);
        int s=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                vector<int> a;
                dfs(i,a);
                sort(a.begin(),a.end());

                for(int j=0;j<a.size();j++)
                    printf("%c,",a[j]+97);
                printf("\n");
                s++;
            }
        }
        printf("%d connected components\n\n",s);

        for(int i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
