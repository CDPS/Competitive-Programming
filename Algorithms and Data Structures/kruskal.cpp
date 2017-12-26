#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int>  edge;

vector< pair< double, edge> > g;

int parent[101],Rank[101];

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;}
    if(Rank[py]< Rank[px]){ parent[py]=px;}
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
}

double kruskal(bool check) {

    int pu, pv;
    sort(g.begin(), g.end());

    if(check)reverse(g.begin(),g.end());

    double ans = 0.0;
    for(int i=0;i<g.size(); i++) {
        pu = findset(g[i].second.first); pv = findset(g[i].second.second);
        if(pu != pv)
            ans = ans + g[i].first, unionset(pu, pv);
    }
    return ans;
}


int main(){
    g.push_back( make_pair(w, make_pair(u,v)));
    kruskal(0);//minimum
    kruskal(1);//maximum
    return 0;
}
