#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second


int t, n, x, y;

vector<int> g[200001];

bool   vs[200001];
int level[200001];

int bfs(int x){

    queue< pair<int,int> > q;

    vs[x] = 1;
    q.push({x, 1});

    int ans = 0;
    while(!q.empty()){

        auto u = q.front(); q.pop();
        level[u.s]++;
        ans = max(level[u.s], ans);

        for(int i=0; i< g[u.f].size();i++)
            if(!vs[g[u.f][i]] )
                q.push({g[u.f][i], u.s+1}), vs[g[u.f][i]] = 1;
    }
    return ans;
}

int solve(){

    cin >> n;

    for(int i=1;i<=n;i++){
        g[i].clear();
        vs[i] = 0;
        level[i] = 0;
    }

    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = g[1].size() + 1;
    for(int i=2;i<=n;i++)
        ans = max(ans, (int)g[i].size());

    return max(ans, bfs(1));
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
