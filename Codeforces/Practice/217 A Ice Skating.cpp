#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int parent[100000];
int Rank  [100000];
int n, m, x, y;

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    n--;
    if(Rank[px]< Rank[py]){ parent[px]=py;  }
    if(Rank[py]< Rank[px]){ parent[py]=px;  }
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
}

int solve(){

    cin >> m ;

    n  = m;
    vector<pair<int,int> > v;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        v.push_back({x, y});
        parent[i]=i; Rank[i] = 1;
    }

    for(int i=0;i < m ; i++)
        for(int j = i + 1; j < m; j++)
            if(v[i].f == v[j].f || v[i].s == v[j].s)
                unionset(i, j);
    return n - 1;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);


    cout << solve() << "\n";

    return 0;
}
