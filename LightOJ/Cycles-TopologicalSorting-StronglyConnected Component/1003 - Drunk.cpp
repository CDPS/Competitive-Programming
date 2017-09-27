#include <bits/stdc++.h>

using namespace std;

map<string, vector<string> > g;
map<string, int >  color;

bool dfs(string u){
    color[u]=1;
    bool res=false;
    for(int i=0;i<g[u].size();i++){
        string v = g[u][i];
        if(color[v]==0){
            res = dfs(v);
            if(res)
                break;
        }
        else if(color[v]==1)
                return true;
    }
    color[u]=2;
    return res;
}

int main(){

    int t,caseno=1;

    scanf("%d",&t);

    while(t--){

        int m;
        scanf("%d",&m);
        string u, v;

        for(int i=0;i<m;i++){
            cin >> u >> v;
            g[u].push_back(v);
            color[u]=0;
            color[v]=0;
        }

        map<string,vector<string> >::iterator it=g.begin();
        bool res=0;
        for (; it!=g.end(); ++it){
                string u = it->first;
                if(color[u]==0){
                    res|= dfs(u);
                }
        }

        if(res)
            printf("Case %d: No\n",caseno++);
        else
            printf("Case %d: Yes\n",caseno++);

        g.clear();
        color.clear();
    }

    return 0;
}
