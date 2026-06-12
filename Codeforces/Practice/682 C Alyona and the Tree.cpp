#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;


int t = 1, n;
ll    w[100001];
int vs[100001];

vector< pair<int,int> > g[100001];

void dfs(int u, ll acc){

    if(w[u]  < acc) return;

    vs[u] = true;

    for(int i=0; i < g[u].size(); i++ ){
        int  v = g[u][i].f;
        int ci = g[u][i].s;
        if(!vs[v])
            dfs(v, max(0LL, acc + ci));
    }
}

int pi, ci;

int solve(){

    cin >> n;
    for(int i=1; i<=n; i++) cin >> w[i];

    for(int i=2; i<=n; i++){
        cin >> pi >> ci;
        g[i].push_back( {pi, ci});
        g[pi].push_back({i , ci});
    }

    dfs(1, 0);

    int ans = 0;
    for(int i= 1; i <=n; i++)
        ans+= !vs[i];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
