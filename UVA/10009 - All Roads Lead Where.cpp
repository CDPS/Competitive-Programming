#include <bits/stdc++.h>

using namespace std;

map< string, vector<string>  > g;
set<string> visit;


struct node{
    string path,v;
    node(string a,string b): v(a),path(b){}
};

string bfs(string s,string t){

    string init = ""; init = init + s[0];
    queue<node> q; q.push(node(s,init));
    visit.insert(s);

    while(!q.empty()){

        node u = q.front(); q.pop();
        string us    = u.v;
        string cpath = u.path;

        if(us == t) return cpath;
        for(int i=0;i<g[us].size();i++){

            string vs = g[us][i];
            if(visit.find(vs)==visit.end()){
                visit.insert(vs);
                q.push(node(vs,cpath + vs[0] ));
            }
        }
    }
    return "";
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,m,q;

    cin >> t;

    bool first = true;
    string u,v;
    while(t--){
        cin >> m >> q;

        if(!first) cout << "\n";
        first = false;
        for(int i=0;i<m;i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        while(q--){
            cin >> u >> v;
            cout << bfs(u,v) << "\n";
            visit.clear();
        }
        g.clear();
    }
    return 0;
}
