#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int v[8][8];
int l[8][8];

int xa[8]={1, 1, 2, 2, -1, -1, -2, -2};
int ya[8]={2, -2, 1, -1, 2, -2, 1, -1};

bool isValid(int x,int y){
    if(x>=0 && x<8 && y>=0 && y<8)
        return true;
    return false;
}

int bfs(int xs, int ys, int xt,int yt){

    memset(v,0,sizeof v);
    memset(l,0,sizeof l);

    queue<node> q;
    q.push(make_pair(xs,ys));

    v[xs][ys]=1;

    while(!q.empty()){
        node u = q.front(); q.pop();

        if(u.first== xt && u.second==yt)
            return l[u.first][u.second];

        for(int i=0;i<8;i++){

            int vx = u.first  +  xa[i];
            int vy = u.second +  ya[i];

            if(isValid(vx,vy) && !v[vx][vy]){
                q.push(make_pair(vx,vy));
                v[vx][vy]=1;
                l[vx][vy]= 1+ l[u.first][u.second];
            }
        }
    }
    return -1;
}

int main(){
    string a,b;
    while(cin >> a >> b)
        cout << "To get from "<< a << " to " << b << " takes " << bfs(a[1]-'0'-1,a[0]-'a',b[1]-'0'-1,b[0]-'a') << " knight moves.\n";
    return 0;
}
