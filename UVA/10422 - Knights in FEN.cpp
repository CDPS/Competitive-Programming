#include<bits/stdc++.h>

using namespace std;

map<  vector< vector<int> > , int > mp;

int init[5][5] = { {1,1,1,1,1},{0,1,1,1,1}, {0,0,2,1,1},{0,0,0,0,1} , {0,0,0,0,0} };
int xs[8]      = {1,-1, 1,-1, 2, 2,-2,-2};
int ys[8]      = {2, 2,-2,-2, 1,-1, 1,-1};


struct node{
    vector< vector<int> >c; int level, x, y;
    node (vector< vector<int> > a, int b, int d, int e):c(a),level(b),x(d),y(e){}
};

bool isValid(int x, int y){
    return x >=0 && x< 5 && y>=0 && y<5;
}

void bfs(){

    vector< vector<int> > s ( 5, vector<int> (5));
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            s[i][j] = init[i][j];

    mp[ s ] = 0; queue<node> q; q.push(node(s,0,2,2));

    while(!q.empty()){

        node u = q.front(); q.pop();

        if(u.level == 10) continue;

        for(int i=0;i<8;i++){
               int vx = u.x + xs[i];
               int vy = u.y + ys[i];

               if(isValid(vx,vy)){

                    char c1 = u.c[u.x][u.y];
                    char c2 = u.c[vx][vy];
                    u.c[u.x][u.y] = c2;
                    u.c[vx][vy] = c1;


                    if(mp.find(u.c) == mp.end() ){
                        mp.insert( make_pair(u.c, 1 + u.level) );
                        q.push(node(u.c,1 + u.level,vx,vy));
                    }
                    u.c[u.x][u.y] = c1;
                    u.c[vx][vy] = c2;
               }
        }
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    bfs();

    int t;
    cin >> t;
    string line;
    vector< vector<int> > g ( 5, vector<int> (5));
    cin.ignore();

    while(t--){

        for(int i=0;i<5;i++){
            getline(cin,line);
            for(int j=0;j<5;j++){
                if(line[j]=='1') g[i][j] =1;
                if(line[j]=='0') g[i][j] =0;
                if(line[j]==' ') g[i][j] =2;
            }
        }

        if(mp.find(g) != mp.end() )
            cout << "Solvable in " << mp[g] << " move(s).\n";
        else
            cout << "Unsolvable in less than 11 move(s).\n";
    }
    return 0;
}
