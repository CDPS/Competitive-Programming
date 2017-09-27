#include <bits/stdc++.h>


using namespace std;

int persons[101];
vector<int> g[1001];
bool visit[1001];
int nodes[1001];

int main(){

    int t,caseno=1;

    scanf("%d",&t);

    while(t--){

         for(int i=0;i<1001;i++){
            g[i].clear();
            nodes[i]=0;
        }

        int k,n,m;
        scanf("%d %d %d",&k,&n,&m);

        for(int i=1;i<=k;i++){
            scanf("%d",&persons[i]);
        }

        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
        }


        for(int i=1;i<=k;i++){

            memset(visit,0,sizeof visit);

            queue<int> q;
            q.push(persons[i]);
            visit[persons[i]]=1;
            nodes[persons[i]]++;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int i=0;i<g[u].size();i++){
                    int v = g[u][i];

                    if(!visit[v]){
                        q.push(v);
                        nodes[v]++;
                        visit[v]=1;
                    }
                }

            }
        }

        int res=0;
        for(int i=1;i<=n;i++){
            if(nodes[i]==k)
                res++;
        }

        printf("Case %d: %d\n",caseno++,res);
    }

    return 0;
}
