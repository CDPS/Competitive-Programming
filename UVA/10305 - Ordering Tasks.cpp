#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int> g[1000], t[1000];
stack<int> s;

int visit[1000];
string ans;

string toString(int u){
    stringstream ss;string s;
    ss << u; ss >> s;
    return s;
}

void dfs(int u){
    visit[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(!visit[v])
            dfs(v);
    }
    s.push(u);
}

void dfst(int u){
    ans= ans+ toString(u+1) + " ";
    visit[u]=1;
    for(int i=0;i<t[u].size();i++){
        int v= t[u][i];
        if(!visit[v])
            dfst(v);
    }
}


void kosaraju(){

    for(int i=0;i<n;i++)
        visit[i]=0;

    for(int i=0;i<n;i++)
        if(!visit[i])
            dfs(i);

   for(int i=0;i<n;i++)
        visit[i]=0;

    ans="";
    while(!s.empty()){
        int u = s.top(); s.pop();
        if(!visit[u])
            dfst(u);
    }
}

int main(){
    int u,v;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0)
            break;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v); u--; v--;
            g[u].push_back(v); t[v].push_back(u);
        }
        kosaraju();
        cout << ans.substr(0,ans.size()-1) << "\n";
        for(int i=0;i<n;i++)
            g[i].clear(),t[i].clear();
    }
    return 0;
}
