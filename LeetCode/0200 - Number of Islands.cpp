class Solution {
public:

    bool visit[300][300];
    int xs [4] = {1,-1,0,0};
    int ys [4] = {0,0,1,-1};

    int n,m;

    bool canVisit(int x, int y, vector<vector<char>>& grid){
        return x>=0 && 
              x < n && 
              y>=0  && 
              y < m && 
              grid[x][y]=='1' && !visit[x][y];
    }

    void bfs(int x, int y, vector<vector<char>>& grid){

        queue<pair<int,int>> q;
        visit[x][y] = true;
        q.push(make_pair(x,y));
        while(!q.empty()){

            pair<int,int> u = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int vx = u.first + xs[i];
                int vy = u.second + ys[i];
                if(canVisit(vx,vy,grid)){
                    q.push(make_pair(vx,vy));
                    visit[vx][vy] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(canVisit(i,j,grid)){
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }

        return ans;
    }
};