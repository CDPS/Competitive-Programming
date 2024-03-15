class Solution {
public:
    
    int dp[200][200];

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){ 
            if(i>0) grid[i][0]|= grid[i-1][0]; 
            if(!grid[i][0]) dp[i][0] = 1;
        }
		
        for(int i=0;i<m;i++){ 
            if(i>0) grid[0][i]|= grid[0][i-1]; 
            if(!grid[0][i]) dp[0][i] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!grid[i][j]){
                    if(!grid[i-1][j]) dp[i][j] += dp[i-1][j];
                    if(!grid[i][j-1]) dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];        
    }
};