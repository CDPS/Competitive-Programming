#include <bits/stdc++.h>
#define edge pair< long, long >

using namespace std;

vector< pair< long, edge > > g;

long parent[1000000];
long Rank  [1000000];
long n;

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;}
    if(Rank[py]< Rank[px]){ parent[py]=px; }
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
}

long long kruskal(bool check) {

    long i, pu, pv;
    sort(g.begin(), g.end());

    if(check==1)reverse(g.begin(),g.end());

    long long res = 0;

    for(i=0; i< g.size(); i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);
        if(pu != pv) {
            res+= g[i].first;
            unionset(pu, pv);
        }
    }

    return res;
}

int main(){

    long  u,v,w;
    long long fcost =0;

    bool first = 1;

    while(scanf("%ld",&n) ==1 ){

        if(!first)printf("\n");
        first=0;

        fcost =0;
        parent[0]=0; Rank[0]=1;
        for(long i=0;i<n-1;i++){
            parent[i+1]=i+1; Rank[i+1]=1;
            scanf("%ld %ld %ld",&u,&v,&w);
            fcost+=w;
        }

        int k ;
        scanf("%d",&k);
        while(k--){
            scanf("%ld %ld %ld",&u,&v,&w);
            u--; v--;
            g.push_back(make_pair(w,edge(u,v)));
        }

        long long m;

        scanf("%lld",&m);

        for(long long i=0;i<m;i++){
            scanf("%ld %ld %ld",&u,&v,&w);
            u--; v--;
            g.push_back(make_pair(w,edge(u,v)));
        }

        printf("%lld\n",fcost);
        printf("%lld\n",kruskal(0));
        g.clear();
    }
    return 0;
}
