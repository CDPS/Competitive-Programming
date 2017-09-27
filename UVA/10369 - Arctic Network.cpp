#include <bits/stdc++.h>

#define edge pair< int, int >

using namespace std;

vector< pair< double, edge > > g;

vector< pair<int,int> > v;

int parent[501];
int Rank  [501];
int n,s;

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
    n--;
}

double kruskal(bool check) {

    int i, pu, pv;
    sort(g.begin(), g.end());

    if(check==1)reverse(g.begin(),g.end());

    double res = -1;

    for(i=0; n > s; i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);

        if(pu != pv) {
            res = max(g[i].first,res);
            unionset(pu, pv);
        }
    }

    return res;
}

double dis(int x1, int y1, int x2, int y2){
    return sqrt( ( (x1-x2)*(x1-x2) ) +   ( (y1-y2)*(y1-y2) ) );
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&s,&n);
        int x,y;

        for(int i=0;i<n;i++){
            parent[i]=i;
            Rank[i]=1;
            scanf("%d %d",&x,&y);
            v.push_back(make_pair(x,y));
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double d = dis(v[i].first,v[i].second,v[j].first,v[j].second);
                g.push_back( make_pair( d, edge(i,j)) )  ;
            }
        }
        printf("%.2lf\n",kruskal(0));
        v.clear();  g.clear();
    }
    return 0;
}
