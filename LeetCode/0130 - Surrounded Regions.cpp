class Solution {
public:

    bool visit[200][200];
    int xs [4] = {1,-1,0,0};
    int ys [4] = {0,0,1,-1};

    int n,m;

    bool canVisit(int x, int y, vector<vector<char>>& board){
        return x>=0 && 
              x < n && 
              y>=0  && 
              y < m && 
              board[x][y]=='O' && !visit[x][y];
    }

    void bfs(int x, int y, vector<vector<char>>& board, bool canReplace){

        queue<pair<int,int>> q;
        visit[x][y] = true;
        q.push(make_pair(x,y));
        while(!q.empty()){

            pair<int,int> u = q.front();
            q.pop();

            if(canReplace)
                board[u.first][u.second] = 'X';
            
            for(int i=0;i<4;i++){
                int vx = u.first + xs[i];
                int vy = u.second + ys[i];
                if(canVisit(vx,vy,board)){
                    q.push(make_pair(vx,vy));
                    visit[vx][vy] = true;
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            if(canVisit(i,0,board))   bfs(i,0,board, false);
            if(canVisit(i,m-1,board)) bfs(i,m-1,board, false);
        }

        for(int i=0;i<m;i++){
            if(canVisit(0,i,board))   bfs(0,i,board, false);
            if(canVisit(n-1,i,board)) bfs(n-1,i,board, false);
        }

        for(int i=1;i<n-1;i++)
            for(int j=1;j<m-1;j++)
                if(canVisit(i,j,board))
                     bfs(i,j,board, true);
    }
};