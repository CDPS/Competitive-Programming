#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> edge;

int dist[101];
vector< edge > g[101];

int n, m;
const int INF = 2000000000;

int dijkstra(int s,int t){

    priority_queue<edge, vector<edge>, greater<edge> > pq;

    for(int i=1;i<=n;i++) dist[i]=INF;

    pq.push(make_pair (0, s));
    dist[s] = 0;

    while (!pq.empty()){

        edge u = pq.top();
        pq.pop();

        if (u.second == t)
            return dist[u.second];

        int here = u.second;

        for (int i=0;i<g[here].size();i++){

            int v = g[here][i].second;
            int wv= g[here][i].first;

            if(dist[here] +  wv < dist[v]){
                dist[v] = dist[here] + wv;
                pq.push(make_pair(dist[v],v));
            }
        }
  }

  return -1;
}

int main(){

    int t,caseno=1;

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);

        while(m--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back( make_pair(w,v));
            g[v].push_back( make_pair(w,u));

        }

        int res= dijkstra(1,n);

        if(res>=0) printf("Case %d: %d\n",caseno++,res);
        else printf("Case %d: Impossible\n",caseno++);

        for(int i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
