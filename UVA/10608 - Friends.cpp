#include <bits/stdc++.h>

using namespace std;

int parent[30000];
int Rank  [30000];
int cant  [30000];

int n,m,maxi;

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
    if(Rank[px]< Rank[py]){ parent[px]=py;  cant[py]+= cant[px]; maxi= max(cant[py],maxi);}
    else if(Rank[py]< Rank[px]){ parent[py]=px; cant[px]+= cant[py]; maxi= max(cant[px],maxi) ;}
    else { parent[py]=px; Rank[px]++; cant[px]+= cant[py]; maxi= max(cant[px],maxi);}
}

int main(){

    int t;
    scanf("%d",&t);

    int p1,p2;
    while(t--){

        scanf("%d %d",&n,&m);

        maxi=1;
        for(int i=0;i<n;i++){
            parent[i]=i; Rank[i] = cant[i]=1;
        }

        while(m--){
            scanf("%d %d",&p1,&p2);
            p1--; p2--;
            unionset(p1,p2);
        }
        printf("%d\n",maxi);
    }

    return 0;
}
