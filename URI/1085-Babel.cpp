#include <bits/stdc++.h>

using namespace std;

struct node{
    string l,w;
    int level;
    node(string a,string b,int c):l(a),w(b),level(c){}
    bool operator < (const node &a) const{
        return  level > a.level;
    }
};

map<string, vector<node> > mp;
set<string> visit;
map<string,int> level;


int dijkstra(string s,string t){

    priority_queue<node, vector<node> > pq;
    pq.push(node(s,"",0));
    visit.insert("");
    level[""]=0;

    while(!pq.empty()){
        node u = pq.top(); pq.pop();
        if(u.l==t){
            return level[u.w];
        }
        for(int i=0;i< mp[u.l].size();i++){
            node v = mp[u.l][i];
            if(!(u.w[0]==v.w[0]) ){
                if( visit.count(v.w)==0 || level[u.w]+v.level < level[v.w] ){
                    level[v.w] = level[u.w]+v.level;
                    visit.insert(v.w);
                    pq.push(node(v.l,v.w,level[v.w]));
                }
            }
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true){
        int n; cin >> n;

        if(n==0)
            break;
        string s,t;

        cin >> s >> t;

        string u,v,w;

        for(int i=0;i<n;i++){
            cin >> u >> v >> w;
            mp[u].push_back(node(v,w,w.size()));
            mp[v].push_back(node(u,w,w.size()));
        }


        if(mp.count(t)==0){
            cout <<"impossivel"<< "\n";
            mp.clear();
            visit.clear();
            level.clear();
            continue;
        }

        int res = dijkstra(s,t);

        if(res==-1)
            cout <<"impossivel"<< "\n";
        else
            cout << res << "\n";

        mp.clear();
        visit.clear();
        level.clear();
    }
    return 0;
}
