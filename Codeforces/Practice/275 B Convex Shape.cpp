#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n, m;
string g[50];
bool vs[50][50];

int check_h(int tx, int ty, int sx, int sy){

    int total = 0;
    if(sy >= ty){
        for(int i = sy; i >= ty; i--){
            if(g[sx][i] == 'B') total++;
        }
    }else{
        for(int i = sy; i <= ty; i++){
            if(g[sx][i] == 'B') total++;
        }
    }

    for(int i = sx; i >= tx; i-- )
          if(g[i][ty] == 'B')
                total++;

    return total;
}

int check_v(int tx, int ty, int sx, int sy){

    int total = 0;
    for(int i = sx; i >= tx; i-- )
          if(g[i][sy] == 'B') total++;

    if(sy >= ty){
        for(int i = sy; i >= ty; i--){
            if(g[tx][i] == 'B') total++;
        }
    }else{
        for(int i = sy; i <= ty; i++){
            if(g[tx][i] == 'B') total++;
        }
    }

    return total;
}

bool solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> g[i];

    vector<pair<int,int>> b;
    for(int i=0;i<n;i++)
        for(int j=0; j < m; j++)
            if(g[i][j] == 'B')
                b.push_back({i,j});

    for(int i=0;i <b.size(); i++){
        for(int j=i+1; j <  b.size(); j++){

            int horizontal = check_h(b[i].f, b[i].s, b[j].f, b[j].s );
            int vertical   = check_v(b[i].f, b[i].s, b[j].f, b[j].s );

            int manhattan = abs( b[i].f - b[j].f ) + abs( b[i].s - b[j].s ) ;

            int target = manhattan + 2;
            if( horizontal != target && vertical != target)
                return false;
        }
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
