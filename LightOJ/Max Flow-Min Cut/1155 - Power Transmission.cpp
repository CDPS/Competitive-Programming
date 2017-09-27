#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
LL inf = 20000;
 
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};
 
struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;
 
  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}
 
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
 
  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }
 
  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
 
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }
 
  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
    dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }
 
  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
    Gap(dist[v]);
      else
    Relabel(v);
    }
  }
 
  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
 
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
 
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};
 
 
 
int main(){
 
    int t,caseno=1;
 
    scanf("%d",&t);
 
    while(t--){
 
        int n;
        scanf("%d",&n);
 
        PushRelabel pr( (2*n) +2);
 
        int c;
 
        for(int i=0;i<n;i++){
            scanf("%d",&c);
            pr.AddEdge(i+1+n, i+1, c);
        }
 
        int m;
 
        scanf("%d",&m);
 
        int i,j;
        while(m--){
            scanf("%d %d %d",&i,&j,&c);
            pr.AddEdge(i, j+n, c);
        }
 
        int b,d;
        scanf("%d %d",&b,&d);
        int node;
 
        for(int i=0;i<b;i++){
            scanf("%d",&node);
            pr.AddEdge(0,node+n,inf);
        }
 
        for(int i=0;i<d;i++){
            scanf("%d",&node);
            pr.AddEdge(node ,(2*n)+1, inf );
        }
 
        LL res = pr.GetMaxFlow(0, (2*n) +1);
 
        printf("Case %d: %d\n",caseno++,res);
    }
 
    return 0;
}
