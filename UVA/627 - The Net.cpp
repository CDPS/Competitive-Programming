#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<int> g[301];
bool visit[301];
int  level[301];

struct node{
    string path;
    int x;
    node(int a,string b):x(a),path(b){}
};

string toString(int x){
    stringstream ss; ss << x;
    string s; ss >> s;
    return s;
}

void bfs(int s, int t){

    for(int i=0;i<301;i++)visit[i]=0;

    level[s]=0; visit[s]=1;
    queue<node> q; q.push(node(s,toString(s)));

    bool f = false;
    string minPath;
    while(!q.empty()){

        node u = q.front(); q.pop();

        if(u.x==t && !f ){ f=true;      minPath = u.path; continue; }
        if(u.x==t &&  f ){ minPath = min(minPath,u.path); continue; }

        for(int i=0;i<g[u.x].size();i++){
            int v = g[u.x][i];
            if(!visit[v]){
                level[v] = 1 + level[u.x];
                visit[v]= 1;
                q.push(node(v,u.path + " " + toString(v)));
            }else if( 1+ level[u.x] == level[v] ){
                q.push(node(v,u.path + " " + toString(v)));
            }
        }
    }

    cout << ((f)? minPath: "connection impossible") << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    string line;
    int u,v;
    char c;

    while(cin >> n){
        cin.ignore();

        for(int i=0;i<n;i++){
            getline(cin,line);
            line += ',';
            stringstream ss(line);
            ss >> u >> c;
            while(ss >> v >> c){
                g[u].push_back(v);
            }
        }

        cin >> q;
        cout << "-----\n";
        while(q--){
            cin >> u >> v;
            bfs(u,v);
        }

        for(int i=0;i<=300;i++)g[i].clear();
    }
    return 0;
}
