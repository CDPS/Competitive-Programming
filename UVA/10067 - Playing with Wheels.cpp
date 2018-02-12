#include <bits/stdc++.h>

using namespace std;

struct node{
    int d[4];
    node(int x,int y, int w, int z){
        d[0] = x; d[1]=y; d[2]=w;d[3]=z;
    }
    bool operator == (const node &a) const{
        return d[0] == a.d[0] && d[1] == a.d[1] && d[2] == a.d[2]  && d[3] == a.d[3];
    }
}; vector<node> forbiden;

bool visit[10][10][10][10];
int  level[10][10][10][10];

int bfs(node s,node t){

    queue<node> q;
    visit[s.d[0]][s.d[1]][s.d[2]][s.d[3]] = 1;
    level[s.d[0]][s.d[1]][s.d[2]][s.d[3]] = 0;

    q.push(s);
    while(!q.empty()){

        node u = q.front(); q.pop();

        if(u== t) return level[u.d[0]][u.d[1]][u.d[2]][u.d[3]];

        for(int i=0;i<4;i++){

            node v =  u;
            v.d[i] = (v.d[i] + 1)%10;
            if(!visit[v.d[0]][v.d[1]][v.d[2]][v.d[3]]){
                visit[v.d[0]][v.d[1]][v.d[2]][v.d[3]] = 1;
                level[v.d[0]][v.d[1]][v.d[2]][v.d[3]] = 1 + level[u.d[0]][u.d[1]][u.d[2]][u.d[3]];
                q.push(v);
            }

            v =  u;
            v.d[i] = (v.d[i] - 1 + 10 )%10;
            if(!visit[v.d[0]][v.d[1]][v.d[2]][v.d[3]]){
                visit[v.d[0]][v.d[1]][v.d[2]][v.d[3]] = 1;
                level[v.d[0]][v.d[1]][v.d[2]][v.d[3]] = 1 + level[u.d[0]][u.d[1]][u.d[2]][u.d[3]];
                q.push(v);
            }
        }
    }
    return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,a,b,c,d,n;
    cin >> t;
    while(t--){

        cin >> a >> b >> c >> d;node u(a,b,c,d);
        cin >> a >> b >> c >> d;node v(a,b,c,d);

        cin >> n;
        memset(visit,0, sizeof visit);
        for(int i=0;i<n;i++){
            cin >> a >> b >> c >> d;
            visit[a][b][c][d]=1;
        }
        cout << bfs(u,v) << "\n";
    }
    return 0;
}
