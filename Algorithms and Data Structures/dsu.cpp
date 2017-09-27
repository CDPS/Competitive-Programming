#include <bits/stdc++.h>

using namespace std;

int parent[100000]; //valor representativo del set
int Rank  [100000]; //maxima altura del set
int cant  [100000]; //Cantidad de nodos por set
int n;              //Cantidad de sets

//Path Compression
int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

//Union By rank
void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;  cant[py]+= cant[px];}
    if(Rank[py]< Rank[px]){ parent[py]=px; cant[px]+= cant[py]; }
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++; cant[px]+= cant[py]; }
}

int main(){

    scanf("%d %d",&n);

    for(int i=0;i<n;i++){
        parent[i]=i; Rank[i] = cant[i]=1;
    }

    return 0;
}
