#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> edge;

vector<edge> g[250];
int t[250][250];

int n,m,c,k;

int dist[250];

const int INF = 2000000000;

int dijkstra(int t){

    priority_queue<edge, vector<edge>, greater<edge> > pq;

    for(int i=0;i<c;i++)
        pq.push(make_pair(dist[i],i));

    while (!pq.empty()){
        edge u = pq.top();
        pq.pop();
        if (u.second == t)
            return dist[u.second];
        int here = u.second;
        for (int i=0;i<g[here].size();i++){
            int v = g[here][i].second;
            if(v>=0 && v<c)
                continue;

            int wv= g[here][i].first;
            if(dist[here] +  wv < dist[v]){
                dist[v] = dist[here] + wv;
                pq.push(make_pair(dist[v],v));
            }
        }
  }
  return -1;
}

 void init(){
    int a = c-1;
    dist[a]=0;
    for(int i=1;i<=c-1;i++){
        if(t[a-i][a-i+1]!=INF)
            dist[a-i]= t[a-i][a-i+1] + dist[a-i+1];
    }
}


int main(){

    while(true){

        scanf("%d %d %d %d",&n,&m,&c,&k);
        if(n==0&&m==0&&c==0&&k==0)
            break;

        for(int i=0;i<n;i++)
            dist[i]=INF;

        memset(t,INF,sizeof t);
        int u,v,w;

        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(make_pair(w,v));
            g[v].push_back(make_pair(w,u));
            t[u][v]=t[v][u]=w;
        }

        init();
        int res= dijkstra(k);
        printf("%d\n",res);
        for(int i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
