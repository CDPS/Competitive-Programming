#include <bits/stdc++.h>

using namespace std;

int t, n, p, ans;

vector<int> g[200002];
int dfs(int u, int l){

    int max_depth = l;

    priority_queue<int , vector<int>, greater<int> > pq;
    for(int v : g[u] ){
        int curr_depth  = dfs( v, l + 1);
        max_depth = max( curr_depth, max_depth);
        pq.push(curr_depth);
        if(pq.size() > 2)
            pq.pop();
    }

    if(pq.size() == 2)
        ans += pq.top() - l;

    return max_depth; 
}

int solve(){

    cin >> n;
    for(int i = 1;i<=n;i++) g[i].clear();
    for(int i=2; i<=n; i++) cin >> p, g[p].push_back(i);
    
    ans = n;
    dfs(1, 1);

    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    
    return 0;
}