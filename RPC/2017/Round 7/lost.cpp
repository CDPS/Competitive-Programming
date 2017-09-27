#include <bits/stdc++.h>

using namespace std;

struct node {

    string u,v; int dist, cost;
    node(string a,string b, int d,int c){ u = a; v = b; dist =d; cost = c; }

    bool operator < (const node &a) const{
        if(dist==a.dist)
            return cost > a.cost;
        return dist > a.dist;
    }
};


priority_queue<node> pq;
map<string, vector<  pair< int, string > > > g;

map<string, int> indexs;

int parent[101]; int Rank [101];


int findset(int x) {
    if(x != parent[x]) parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;}
    if(Rank[py]< Rank[px]){ parent[py]=px;}
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
}

int kruskal() {
    int res = 0;

    while(!pq.empty()){
        node u = pq.top(); pq.pop();
        int pu = findset(indexs[u.u]),pv = findset(indexs[u.v]);
        if(pu != pv)
            res += u.cost,unionset(pu, pv);
    }
    return res;
}


int visit[100],level[100];
int t,n;

bool bfs(){

    memset(visit,0,sizeof visit); memset(level,0,sizeof level);

    visit[0]=1;level[0]=0;

    queue<string> q; q.push("English");

    while(!q.empty()){

        string u = q.front(); q.pop();
        for(int i=0;i<g[u].size();i++){
            string v = g[u][i].second; int cost = g[u][i].first;

            if(!visit[ indexs[v]] ){
                visit[indexs[ v ] ] = 1; level[indexs[ v ]] = 1 +level[ indexs[u] ];
                q.push(v);  pq.push(node(u,v, level[indexs[ v ]],cost));
            }else{
                pq.push(node(u,v, level[indexs[ v ]],cost));
            }
        }
    }

    for(int i=0;i<=t;i++)
        if(visit[i]==0)
            return false;
    return true;
}

int main(){

    cin >> t >> n;

    indexs["English"]=0;
    parent[0]=0; Rank[0]=1;
    string names;

    for(int i=0;i<t;i++){
        cin >> names;indexs[names]=i+1;
        parent[i+1]=i+1; Rank[i+1]=1;
    }

    string u,v;
    int w;

    for(int i=0;i<n;i++){
        cin >> u >> v >> w;
        g[u].push_back(make_pair(w,v)); g[v].push_back(make_pair(w,u));
    }

    if(bfs()) cout << kruskal() << "\n";
    else cout << "Impossible\n";
    return 0;
}
