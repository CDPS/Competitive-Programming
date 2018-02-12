#include <bits/stdc++.h>

using namespace std;
vector<string> g[20];
int    parent[25143];

bool isAdjacent(string u,string v){
    if(u.size()!=v.size()) return false;
    int acc = 0;
    for(int i=0;i<u.size();i++)if(v[i]!=u[i]) acc++;
    return acc == 1;
}

int Find(string x,vector<string> &s){
    for(int i=0;i<s.size();i++)if(x==s[i]) return i;
    return -1;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);

    string u,v; bool first = true;
    while(getline(cin,u)){
        if(u=="") break;
        g[u.size()].push_back(u);
    }

    while(cin >> u >> v){

        if(!first) cout << "\n";

        first = false;

        vector<string> adjacents = g[u.size()];

        int s = Find(u,adjacents);
        int t = Find(v,adjacents);
        if(u.size() != v.size()  || s == -1 || t == -1) {
            cout << "No solution.\n";
        }
        else{

            bool f = false;
            memset(parent,0,sizeof parent);

            queue<int> q; q.push(s); parent[s]=-1;
            while(!q.empty()){

                int ui = q.front(); q.pop();

                if(ui== t) {f = true; break;}

                for(int i =0;i<adjacents.size();i++){
                    if( !parent[i] && isAdjacent(adjacents[ui],adjacents[i])){
                        parent[i] = ui+1;
                        q.push(i);
                    }
                }
            }

            if(f){
                stack<string> st;
                int x = t;
                while(parent[x]!=-1){
                    st.push(adjacents[x]);
                    x = parent[x]-1;
                }
                st.push(adjacents[x]);

                while(!st.empty()) u = st.top(),cout << u << "\n", st.pop();
            }
            else{
                cout << "No solution.\n";
            }
        }
    }
    return 0;
}
