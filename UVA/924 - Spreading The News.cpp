#include <bits/stdc++.h>

using namespace std;

int   days[5000];
int  level[2500];
bool visit[2500];
vector<int> g[2500];

int n,m,x,q;
void bfs(int s){

    for(int i=0;i<n;i++)
        visit[i]=level[i]=days[i]=0;
    days[n]=0;

    visit[s]=1;
    queue<int> q; q.push(s);

    int maxi = 0, mini;
    while(!q.empty()){

        int u = q.front(); q.pop();

        for(int i=0;i<g[u].size();i++){

            int v = g[u][i];

            if(!visit[v]){
                level[v] = 1 + level[u];
                days[ level[v] ]++;
                visit[v] = 1;
                q.push(v);

                if(maxi< days[ level[v] ])
                    maxi = days[ level[v] ] , mini = level[v];
                if(maxi == days[ level[v] ])
                    mini = min(mini,level[v]);
            }
        }
    }

    if(maxi==0) printf("0\n");
    else printf("%d %d\n",maxi,mini);
}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&x);
            g[i].push_back(x);
        }
    }

    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        bfs(x);
    }
    return 0;
}
