#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> point;
typedef pair<int,int>  edge;

vector< pair< double, edge> > g;
vector< pair<int,int> > v;

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

    int i, pu, pv;
    sort(g.begin(), g.end());

    if(check)reverse(g.begin(),g.end());

    double ans = 0.0;

    for(i=0;i<g.size(); i++) {

        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);

        if(pu != pv) {
            ans += g[i].first;
            unionset(pu, pv);
        }
    }

    return ans;
}

double dis(point a,point b){
    return sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){

    int t,n;

    scanf("%d",&t);

    bool first = true;

    while(t--){
        scanf("%d",&n);

        double x,y;
        vector<point> v;
        if(!first) printf("\n");
        first=false;
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            v.push_back(make_pair(x,y));
            parent[i]=i; Rank[i]=1;
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(j!=i)
                    g.push_back( make_pair(dis(v[i],v[j]),make_pair(i,j)));


        double ans = kruskal(0);
        printf("%.2lf\n",ans);
        g.clear();
    }
    return 0;
}
