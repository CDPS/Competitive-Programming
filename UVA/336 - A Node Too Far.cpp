#include <bits/stdc++.h>

using namespace std;

map<int,vector<int> >  g;
set<int > nodes;

int bfs(int s,int t){

    map<int,int> level;
    set<int> visit = nodes;
    queue<int> q;

    visit.erase(s); level[s]=0;
    q.push(s);

    while(!q.empty()){

        int u = q.front(); q.pop();

        if(level[u]==t)
            continue;

        for(int i=0;i< g[u].size();i++){
            int v = g[u][i];

            if(visit.find(v) != visit.end()){
                visit.erase(v);
                level[v] = level[u] +1;
                q.push(v);
            }
        }
    }

    return visit.size();
}

int main(){

    int n,u,v,q,t,caseno=1;

    while(scanf("%d",&n) && n){

        g.clear(); nodes.clear();

        for(int i=0;i<n;i++){
            scanf("%d %d", &u,&v);
            g[u].push_back(v); g[v].push_back(u);
            nodes.insert(u); nodes.insert(v);
        }

        while(scanf("%d %d",&q,&t) && (q || t)){

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caseno++, bfs(q,t),q,t);
        }
    }
    return 0;
}
