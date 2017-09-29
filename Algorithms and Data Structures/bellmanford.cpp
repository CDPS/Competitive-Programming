#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000000;
typedef pair<int,int> edge;

vector<edge> g[200];

int a[200],d[200];

int n,m;

void relax(int u,int v,int w){
    if(d[u]!=INF && d[v] > d[u] +  w ){
        d[v]=d[u]+w;
    }
}


bool bellmanFord(int s){

    for(int i=0;i<n;i++){
        d[i]=INF;
    }

    d[s]=0;

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
             for(int j=0;j<g[i].size();j++){
                int w = g[i][j].first;  int v = g[i][j].second;
                relax(i,v,w);
            }
        }
    }

     for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                int w = g[i][j].first; int v = g[i][j].second;
                if(d[i]!=INF &&  d[v] > d[i] + w )
                    return false;
            }
    }

    return true;
}
