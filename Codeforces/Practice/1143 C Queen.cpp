#include <bits/stdc++.h>

using namespace std;

bool check[100000], color[100000];

vector<int> g[100000], ans;

void dfs(int x){
    if(check[x]) ans.push_back(x);
    for(int i=0; i < g[x].size();i++)
        dfs(g[x][i]);
}

int main(){

    int n, root, p, c;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p >> c;
        if(p==-1){ root = i; continue; }
        g[p-1].push_back(i), color[i] = c;
    }

    for(int i=0;i<n;i++){
        int acc = 0;
        for(int j=0; j < g[i].size();j++)
            if(color[g[i][j]]==1) acc++;
        check[i] = color[i] && acc == g[i].size();
    }

    dfs(root);
    if(ans.size()==0){
        cout << "-1" << "\n";
        return 0;
    }

    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i]+1 << " \n"[i==ans.size()-1];

    return 0;
}
