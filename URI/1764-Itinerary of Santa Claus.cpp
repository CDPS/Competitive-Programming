#include <bits/stdc++.h>

using namespace std;

#define edge pair< int, int >

// ( w (u, v) ) format
vector< pair< int, edge > > g;

int parent[40000], total, n, e;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

int kruskal(bool check) {
    total =0;
    int i, pu, pv;
    sort(g.begin(), g.end()); // increasing weight

    if(check==1)reverse(g.begin(),g.end());

    for(i=total=0; i<g.size(); i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);
        if(pu != pv) {

            total += g[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
    return total;
}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    while( n!=0 || m!=0){

        int u,v,w;

        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g.push_back(make_pair(w, edge(u, v)));
            g.push_back(make_pair(w, edge(v,u)));

        }

        for(int i=0; i<=n; i++)
            parent[i]=i;

        int res= kruskal(0);

        printf("%d\n",res);

        g.clear();
        scanf("%d %d",&n,&m);
    }

    return 0;
}
