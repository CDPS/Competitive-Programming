#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int oo = 1e9;

int t = 1, n;

bool g[120][120];
int bfs(int x){

    vector<int> dist(n, oo);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[x] = 0;
    q.push(x);

    int ans = oo;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++){

            if(!g[u][v]) continue;

            if(dist[v] == oo){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
            else if (parent[u] != v) {
                ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }
    return ans;
}

ll x;
int solve(){

    cin >> n;

    vector<ll> a;
    for(int i=0;i < n; i++){
        cin >> x;
        if(x != 0)
            a.push_back(x);
    }
    n = a.size();

    if(n > 120 ) return 3;

    for(int i=0; i < n; i++)
        for(int j= i+1; j < n; j++)
            if( (a[i] & a[j]) !=0ll)
                g[i][j] = g[j][i] = true;

    int ans = oo;
    for(int i = 0; i < a.size(); i++)
        ans = min(ans, bfs(i) );

    return ans == oo? -1 : ans;
}


int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
