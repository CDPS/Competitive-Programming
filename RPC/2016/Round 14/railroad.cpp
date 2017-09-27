#include <bits/stdc++.h>

using namespace std;

#define MAXNODES 50001
#define edge pair< int, int >

vector< pair< long, edge > > g;

int parent[MAXNODES];
int nodes;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

long kruskal(bool check) {
    long total =0;

    int i, pu, pv;
    sort(g.begin(), g.end());

    if(check==1)reverse(g.begin(),g.end());
    for(i=total=0; i<g.size(); i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);

        if(pu != pv) {
            total += g[i].first;
            parent[pu] = parent[pv];
            nodes++;
        }
    }
    return total;
}


int main(){

    int n,m,l;

    scanf("%d %d %d",&n,&m,&l);

    int u,v,w;

    long length=0;

    for(int i=0;i<l;i++){
        scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        length+=w;
        g.push_back(make_pair(w,edge(u,v)));
    }

    for(int i=l;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        g.push_back(make_pair(w,edge(u,v)));
    }

    for(int i=0; i<=n; i++)
        parent[i]=i;
    nodes=0;
    long minCost= kruskal(0);

    if(nodes==n-1 && minCost<=length)
        printf("possible\n");
    else
        printf("impossible\n");

    return 0;
}

