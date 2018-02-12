#include <bits/stdc++.h>

using namespace std;

struct node{
    int x,y,idx;
    node(int a,int b, int c): x(a),y(b),idx(c){}
};

bool visit[1010];
int  level[1010];
vector<node> g;
double xs, ys, xe,ye,x,y;
double v,m;

bool isAdjacent(node u, node vv){
    double dis = sqrt( ((u.x - vv.x)*(u.x - vv.x)) + ((u.y - vv.y)*(u.y - vv.y))  );
    double t = dis/v;
    return t<=m;
}

int bfs(){

    for(int i=0;i<g.size();i++) visit[i]=0;

    visit[0] = 1; level[0] = 0;

    queue<node> q; q.push(g[0]);

    while(!q.empty()){

        node u  = q.front(); q.pop();

        if(u.idx ==1) return level[1]-1;

        for(int i=0;i<g.size();i++){

            if( u.idx!=i && !visit[i] && isAdjacent(u,g[i])){
                q.push(g[i]);
                visit[i] = 1;
                level[i] = 1 + level [ u.idx ];
            }
        }
    }
    return -1;
}

int main(){

    string line;
    while(cin >> v >> m && !(v==0 && m ==0)){
        m*=60.0;
        cin >> xs >> ys;
        cin >> xe >> ye;
        cin.ignore();

        g.push_back(node(xs,ys,0)); g.push_back(node(xe,ye,1));
        int idx = 2;
        while(getline(cin,line)){
            if(line=="") break;
            stringstream ss(line);
            ss >> x >> y;
            g.push_back(node(x,y,idx++));
        }

        int ans = bfs();
        if(ans == -1 )cout << "No.\n";
        else cout << "Yes, visiting "<< ans << " other holes.\n";
        g.clear();
    }
    return 0;
}
