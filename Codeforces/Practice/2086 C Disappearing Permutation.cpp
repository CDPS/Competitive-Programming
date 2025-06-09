#include <bits/stdc++.h>

using namespace std;

int  a[100001];
int st[100001];
vector<int> g[100001];

int dfs(int u, int sets){
    st[u] = sets;
    int ans = 1;
    for(int i=0;i<g[u].size(); i++)
        if(!st[g[u][i]])
            ans += dfs(g[u][i], sets);
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t , n, x;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<=n;i++) g[i].clear(), st[i] = 0;

        for(int i=1;i<=n;i++){
            cin >> a[i];
            g[a[i]].push_back(i);
            g[i].push_back(a[i]);
        }

        int sets = 1;
        map<int,int> mp;
        for(int i=1;i<=n;i++)
            if(!st[i])
                mp[sets]= dfs(i, sets), sets++;

        int ans = 0;
        set<int> st2;
        for(int i=0;i<n;i++){
            cin >> x;
            if(!st2.count( st[a[x]] ) )
                ans+= mp[st[a[x]]], st2.insert(st[a[x]]);

            cout << ans << " \n"[i==n-1];
        }
    }
    return 0;
}
