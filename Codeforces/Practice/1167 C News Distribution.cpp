#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int parent[500000];
int Rank  [500000];
int cant  [500000];

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py; cant[py]+= cant[px];}
    if(Rank[py]< Rank[px]){ parent[py]=px; cant[px]+= cant[py]; }
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++; cant[px]+= cant[py]; }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int u, v;

    cin >> n >> m;

    for(int i=0;i<n;i++)
        parent[i]=i, Rank[i] = cant[i]=1;

    while(m--){
        cin >> k;
        if(k){
            k--;
            cin >> u;
            while(k--) cin >> v, unionset(u-1,v-1);
        }
    }

    for(int i=0;i<n;i++)
        cout << cant[findset(i)] <<" \n"[i==n-1];

    return 0;
}
