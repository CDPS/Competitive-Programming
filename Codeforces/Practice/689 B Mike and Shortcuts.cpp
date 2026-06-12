#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int t = 1, n;

int    a[200001];
int dist[200001];

void bfs(){

    queue<int> q;
    q.push(1); dist[1] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u + 1 <= n && dist[u + 1] > dist[u] + 1)
            q.push(u + 1), dist[u+1] = dist[u] + 1;
        if(u - 1 >= 1 && dist[u - 1] > dist[u] + 1)
            q.push(u - 1), dist[u-1] = dist[u] + 1;
        if( dist[ a[u] ] > dist[u] + 1)
            q.push(a[u]), dist[a[u]] = dist[u] + 1;
    }
}

void solve(){

    cin >> n;
    for(int i=1; i <= n; i++)
        cin >> a[i], dist[i] = oo;

    bfs();
    for(int i=1; i <=n; i++)
        cout << dist[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
