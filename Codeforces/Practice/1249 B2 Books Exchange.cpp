#include <bits/stdc++.h>

using namespace std;

int t, n;

int      p[200001];
int in_set[200001];

int dfs(int u, int st){

    if(in_set[u] !=-1) return 0;

    in_set[u] = st;

    return 1 + dfs( p[u], st);
}

void solve(){

    cin >> n;
    for(int i= 1; i <=n; i++)
        cin >> p[i], in_set[i] = -1;

    vector<int> level;
    for(int i= 1, curr= 0; i<=n; i++)
        if(in_set[i] == -1)
            level.push_back(dfs(i, curr++));

    for(int i= 1; i <=n; i++)
        cout << level[in_set[i]] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

