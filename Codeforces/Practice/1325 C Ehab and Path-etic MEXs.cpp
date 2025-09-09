#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];
map< pair<int, int>, int> mp;

int ans[100001];

int main(){

    int n, u, v;
    cin >> n;

    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u,v}] = i;
        mp[{v,u}] = i;
        ans[i] = -1;
    }
    ans[n] = 1;

    int curr = 0;
    for(int i=1;i<=n;i++){
        if(g[i].size() >= 3){
            for(int j=0;j<g[i].size();j++)
                ans[mp[{ i, g[i][j] } ]]= curr++;
            break;
        }
    }

    for(int i=0;i<n-1;i++){
        if(ans[i]==-1)
            ans[i] = curr++;
        cout << ans[i] << "\n";
    }

    return 0;
}
