#include <bits/stdc++.h>

using namespace std;
#define edge pair< int, int >

int n,m;
vector< pair< int, edge > > g;

int parent[200000];


int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

int kruskal(bool check) {
    int total =0;

    int i, pu, pv;
    sort(g.begin(), g.end()); // increasing weight

    if(check==1)reverse(g.begin(),g.end());

    for(i=total=0; i<g.size(); i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);

        if(pu != pv) {
            total += g[i].first;
            parent[pu] = parent[pv];
        }
    }
    return total;
}

int main(){

    while(true){

        scanf("%d %d",&n,&m);

        if(n==0 && m==0)
            break;

        int u,v,w;
        int total=0;
        for(int i=0;i<m;i++){
            scanf("%d %d %d", &u,&v,&w);
            g.push_back(make_pair(w,edge(u,v)));
            total+=w;
        }

        for(int i=0; i<=n; i++)
            parent[i]=i;

        int minCost= kruskal(0);

        printf("%d\n",total- minCost);

        g.clear();

    }

    return 0;
}
