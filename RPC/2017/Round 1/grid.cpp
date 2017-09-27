#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

const string endline = "\n";
const int INF = 1000000;


int n,m;

string  grid[500];
int level[500][500];
bool visit[500][500];

int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};

bool isValid(int x, int y){
  if(x>=0 && x <n && y>=0 && y<m)
    return true;
  return false;
}

int bfs(){

  queue<node> q;
  q.push(make_pair(0,0));
  visit[0][0]=1;
  level[0][0]=0;

  while(!q.empty()){
    node u = q.front(); q.pop();

    if(u.first == n-1 && u.second==m-1)
      return level[u.first][u.second];

    for(int i=0;i<4;i++){
      int vx =  u.first + ((grid[u.first][u.second]-'0')*xs[i] );
      int vy =  u.second + ((grid[u.first][u.second]-'0')*ys[i] );
      if(isValid(vx,vy)){
        if(!visit[vx][vy]){
          q.push(make_pair(vx,vy));
          visit[vx][vy]=1;
          level[vx][vy]= level[u.first][u.second] +1;
        }
      }
    }
  }
  return -1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      cin  >> grid[i];
    int ans = bfs();
    if(ans == -1)
        cout << "IMPOSSIBLE" << endline;
    else
        cout << ans << endline;
    return 0;
}
