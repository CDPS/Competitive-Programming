#include <bits/stdc++.h>

using namespace std;


vector<int> g[30];
bool    visit[30];
int     level[30];
int bfs(int x,int y){

    visit[x]=1;
    queue<int> q; q.push(x);

    for(int i =0 ;i<30;i++) visit[i] = level[i]=0;

    while(!q.empty()){

        int u = q.front(); q.pop();

        if(u == y) return level[u];

        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];

            if(!visit[v]){
                visit[v]=1;
                level[v] = level[u] + 100;
                q.push(v);
            }
        }
    }
    return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,caseno=1,n,m,q;
    cin >> t;

    cout << "SHIPPING ROUTES OUTPUT\n\n";
    while(t--){
        cin >> n >> m >> q;
        map<string, int> mp;

        string su,sv;
        for(int i=0;i<n;i++) cin >> su, mp[su]=i;


        for(int i=0;i<m;i++){
            cin >> su >> sv;
            g[ mp[su] ].push_back( mp[sv] );
            g[ mp[sv] ].push_back( mp[su] );
        }

        cout << "DATA SET  " << caseno++ << "\n\n";
        int cost;
        while(q--){
            cin >> cost >> su >> sv;
            int ans = bfs(mp[su],mp[sv]);

            if(ans == -1) cout << "NO SHIPMENT POSSIBLE\n";
            else          cout << "$" << ans*cost << "\n";
        }

        cout << "\n";
        for(int i=0;i<30;i++) g[i].clear();
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
