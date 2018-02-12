#include <bits/stdc++.h>

using namespace std;

vector<int> g[200];
bool    visit[200];
int     level[200];

bool isAdjacent(string a, string b){
    if(a.size()!=b.size()) return false;
    int acc =0;
    for(int i=0;i<a.size();i++) if(a[i]!=b[i]) acc++;
    return acc == 1;
}

int bfs(int s,int t){

    visit[s] = 1;
    queue<int> q; q.push(s);

    while(!q.empty()){

        int u = q.front(); q.pop();

        if(u==t) return level[u];

        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(!visit[v])
                visit[v] = 1, level[v] = 1 + level[u],q.push(v);
        }
    }
    return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    string s; bool first = 1;
    while(t--){

        vector<string>  v;
        map<string,int> mp;

        if(!first) cout << "\n";
        first = 0;
        int idx =0;
        while(cin >> s && s!="*")
            v.push_back(s),mp[s]=idx++;

        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
                if(isAdjacent(v[i],v[j]))
                    g[i].push_back(j),g[j].push_back(i);

        string u,t;
        cin.ignore();
        while(getline(cin,s) && s!=""){

            stringstream ss(s);
            ss >> u >> t;
            for(int i=0;i<200;i++) level[i] = visit[i]=0;

            int ans = bfs(mp[u],mp[t]);
            cout << u << " " << t << " " << ans << "\n";
        }

        for(int i=0;i<200;i++) g[i].clear();
    }
    return 0;
}
