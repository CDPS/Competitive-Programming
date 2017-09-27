#include <bits/stdc++.h>

using namespace std;


#include <bits/stdc++.h>

using namespace std;

int parent[50000];
int Rank  [50000];
int n,m;

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]) parent[px]=py;
    if(Rank[py]< Rank[px]) parent[py]=px;
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
    n--;
}

int main(){

    int caseno=1;

    while(scanf("%d %d",&n, &m)){
        if(n==0 && m==0) break;

        for(int i=0;i<n;i++){
            parent[i]=i; Rank[i]=1;
        }

        int p1,p2;

        for(int i=0;i<m;i++){
            scanf("%d %d",&p1,&p2);
            p1--;p2--;
            unionset(p1,p2);
        }

        printf("Case %d: %d\n",caseno++,n);
    }
    return 0;
}
