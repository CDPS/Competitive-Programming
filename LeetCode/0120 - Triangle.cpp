class Solution {
public:

    int oo=1000000000;
    int dp[301][301];

    int minimumTotal(vector<vector<int>>& triangle) {
                
        int n = triangle.size();
        for(int i=0;i<triangle[n-1].size();i++)
            dp[n-1][i] = triangle[n-1][i];

        for(int i=n-2;i>=0;i--)
            for(int j = 0;j < triangle[i].size();j++)
                dp[i][j] = min( triangle[i][j] + dp[i+1][j]  , triangle[i][j] + dp[i+1][j+1] );
            
        return dp[0][0];
    }
};