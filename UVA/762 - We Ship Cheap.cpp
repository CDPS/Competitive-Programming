#include <bits/stdc++.h>

using namespace std;

map<string,vector<string> > g;
set<string> visit;
map<string,string> parent;

void bfs(string s,string t){

    visit.insert(s);
    parent[s]="-1";

    queue<string> q; q.push(s);
    string x = t;

    bool f= false;
    while(!q.empty()){

        string u = q.front(); q.pop();

        if(u==t){f= true; break;}

        vector<string> l =g[u];
        for(int i=0;i< l.size();i++){
            string v = l[i];
            if(visit.find(v)==visit.end())
                visit.insert(v),parent[v] = u,q.push(v);
        }
    }

    if(f){
        stack<string> st;
        while(parent[x]!="-1") st.push(x), x= parent[x];

        while(!st.empty()){
            x = st.top(); st.pop();
            cout << parent[x] << " " << x << "\n";
        }
    }
    else{
        cout << "No route\n";
    }
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    string u,v; bool first  = true;
    while( cin >> n){

        if(!first) cout << "\n";
        first = false;

        for(int i=0;i<n;i++){
            cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }

        cin >> u >> v;

        bfs(u,v);
        g.clear(); visit.clear(); parent.clear();
    }
    return 0;
}
