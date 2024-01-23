class Solution {
public:

    int n, m;
    int xs[4] = {1,-1,0,0};
    int ys[4] = {0,0,1,-1};
    bool visit[6][6];
    
    bool isValid(int x, int y){
        return x >=0 && x<n && y>=0 && y< m && !visit[x][y];
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, string s, int index){
        
        if(index==s.size())
            return true;
            
        visit[x][y] = true;
        bool ans = false;
        for(int i=0;i<4 && !ans;i++){
            int vx = x + xs[i], vy = y + ys[i];
            if(isValid(vx,vy) &&  board[vx][vy]== s[index])
                ans |=dfs(board, vx, vy, s, index + 1);        
        }
        visit[x][y] = false; 
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();

        bool ans = false;
        for(int i=0;i<n && !ans;i++)
            for(int j=0;j<m && !ans;j++)
                if(board[i][j]==word[0])
                    ans|= dfs(board, i, j, word, 1);
        return ans;
    }
};