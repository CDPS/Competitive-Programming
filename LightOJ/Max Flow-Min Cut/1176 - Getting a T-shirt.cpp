#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef long long LL;
 
LL inf=10000;
 
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
 
 
int main (){
 
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
 
        int c,p;
 
        scanf("%d %d",&c,&p);
 
        PushRelabel pr(14 + p);
 
        map<string,int> mp;
 
        mp["XS"]=p+1;
        mp["S"]=p+2;
        mp["M"]=p+3;
        mp["L"]=p+4;
        mp["XL"]=p+5;
        mp["XXL"]=p+6;
 
        for(int i=1;i<=6;i++){
            pr.AddEdge(p+i,p+6+i,c);
            pr.AddEdge(p+6+i,13+p,inf);
        }
 
        string s1, s2;
 
        for(int i=1;i<=p;i++){
            pr.AddEdge(0,i,1);
            cin >> s1 >> s2;
            pr.AddEdge(i,mp[s1],1);
            pr.AddEdge(i,mp[s2],1);
        }
 
        LL r = p;
        LL res= pr.GetMaxFlow(0,p+13);
        if(res<r){
 
            printf("Case %d: NO\n",caseno++);
        }
        else{
            printf("Case %d: YES\n",caseno++);
        }
    }
 
    return 0;
}
