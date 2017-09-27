#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int visit[8][8];
int level[8][8];

int xs[8]={1, 1, 2, 2, -1, -1, -2, -2};
int ys[8]={2, -2, 1, -1, 2, -2, 1, -1};

bool isvalid(int x,int y){
    if(x>=0 && x<8 && y>=0 &&y<8)
        return true;
    return false;
}
int bfs(node a,node b){

    queue<node> q;
    q.push(a);
    visit[a.first][a.second]=1;
    level[a.first][a.second]=0;

    while(!q.empty()){
        node u = q.front(); q.pop();

        if(u.first==b.first && u.second==b.second)
            return level[u.first][u.second];

        for(int i=0;i<8;i++){
            int vx = u.first +  xs[i];
            int vy = u.second + ys[i];

            if(isvalid(vx,vy)){
                if(!visit[vx][vy]){
                    visit[vx][vy]=1;
                    level[vx][vy]= level[u.first][u.second] + 1;
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
}
int main(){
    string a,b;
    while(cin >> a >> b){
        memset(visit,0,sizeof visit);
        int res = bfs(make_pair(a[1]-'0'-1,a[0]-'a'),make_pair(b[1]-'0'-1,b[0]-'a'));
        cout << "To get from "<<a<<" to " << b <<" takes "<< res<<" knight moves.\n";
    }
    return 0;
}
