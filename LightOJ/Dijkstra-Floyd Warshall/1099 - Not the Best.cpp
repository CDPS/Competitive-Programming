#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;
const int INF = 2000000000;

vector<node> g[5001];
int visit[2][5001];
int dis[2][5001];
int n,m;

struct edge{
    int best,v,w;
    edge(int a,int b, int c){ best=a; v=b; w=c; }

    bool operator < (const edge &a) const {
        if (best == a.best){
            if(w == a.w)
                return v > a.v;
            return w > a.w;
        }
        return best > a.best;
    }
};

int dijkstra(int s,int t){

    for(int i=0;i<=n;i++){
            dis [1][i]=INF;
            dis [0][i]=INF;
    }

    priority_queue<edge> pq;
    pq.push(edge(0,s,0));
    dis[0][s]=1;

    while(!pq.empty()){

        edge u = pq.top();
        pq.pop();

        int b = u.best;
        int here= u.v;
        int dist = u.w;

        if( here == t && b == 1)
            return dis[b][here];


        for(int i=0;i<g[here].size();i++){
            int v = g[here][i].second;
            int wv= g[here][i].first;

            if(dist + wv < dis[0][v]){
                dis[1][v] = dis[0][v];
                dis[0][v] = dist + wv;
                pq.push(edge(0,v,dis[0][v]));
                pq.push(edge(1,v,dis[1][v]));
            }
            else if( dist+ wv > dis[0][v] && dist+wv <dis[1][v] ){
                dis[1][v] = dist + wv;
                pq.push(edge(1,v,dis[1][v]));
            }
        }
    }
    return INF;
}



int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);
        int u,v,w;

        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back( make_pair(w,v));
            g[v].push_back( make_pair(w,u));
        }

        int res = dijkstra(1,n);

        printf("Case %d: %d\n",caseno++,res);

        for(int i=0;i<=n;i++) g[i].clear();
    }
    return 0;
}
