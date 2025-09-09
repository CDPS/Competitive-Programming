#include <bits/stdc++.h>

using namespace std;

int parent[5000];
int Rank  [5000];
int sets;

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;}
    if(Rank[py]< Rank[px]){ parent[py]=px;}
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
    sets--;
}

struct node {
    int x,y, r;
    node(int x, int y, int r) : x(x), y(y), r(r){}
};

bool overlap(const node& c1, const node& c2) {
    return ((c2.x - c1.x)*(c2.x-c1.x))  +
           ((c2.y - c1.y)*(c2.y-c1.y)) < c1.r * c1.r;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, x,y,r;
    while(cin >> n && n){

        vector<node> v;
        for(int i=0;i<n;i++){
            cin >> x >> y >> r;
            v.push_back(node(x,y,r));
            parent[i]=i; Rank[i] =1;
        }

        sets = n;
        for(int i=0;i<n;i++)
            for(int j=0; j<n;j++)
                if(overlap(v[i],v[j]))
                     unionset(i,j);

        cout << sets << "\n";
    }
    return 0;
}
