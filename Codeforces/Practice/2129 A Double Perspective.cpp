#include <bits/stdc++.h>

using namespace std;

int t, n;
int parent[6001];
int   Rank[6001];

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int px, int py){
    if(Rank[px]< Rank[py]){ parent[px]=py;  }
    if(Rank[py]< Rank[px]){ parent[py]=px;  }
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++; }
}

void solve(){

    cin >> n;

    vector<pair<int,int> > a(n);
    for(int i =0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    for(int i=1; i <= 2*n; i++)
        parent[i] = i , Rank[i] = 1;

    vector<int> ans;
    for(int i=0; i <n; i++){
        int u= findset(a[i].first);
        int v= findset(a[i].second);
        if( u != v ){
            unionset(u, v);
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << "\n";
    for(int i=0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
