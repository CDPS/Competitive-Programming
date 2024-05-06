#include <bits/stdc++.h>

using namespace std;

const int INF = 10000000;
typedef pair<int,int> edge;

vector<edge> g[5000];

int d[5000];

int n,m;

void relax(int u,int v,int w){
    if(d[u]!=INF && d[v] > d[u] +  w ){
        d[v]=d[u]+w;
    }
}

bool bellmanFord(int s){

    for(int i=0;i<n;i++)
        d[i]=INF;
    d[s]=0;

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
             for(int j=0;j<g[i].size();j++)
                relax(i,g[i][j].second,g[i][j].first);

     for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                int w = g[i][j].first; int v = g[i][j].second;
                if(d[i]!=INF &&  d[v] > d[i] + w )
                    return false;
            }
    }
    return true;
}

int main(){

    cin >> n >> m;

    int u,v,w;
    char op;

    for(int i=0;i<m;i++){
        cin >> u >> v >> op >> w;
        u--; v--;
        if(op == 'r') w*=-1;
        g[u].push_back(make_pair(w,v));
    }

    bellmanFord(0);

    for(int i=0;i<n;i++){
        if(d[i] < 0)
            cout << i+1 << "\n";
    }
    return 0;
}
