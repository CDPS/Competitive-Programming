class Solution {
public:

    int dp[100];

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n==1)
            return nums[0];
        
        for(int i=0;i<n;i++)
            dp[i] = -1;
        
        dp[0] = nums[0];
        dp[1] = nums[1];

        int ans = max(dp[0], dp[1]);

        for(int i=2;i<n;i++)
            for(int j =0; j < i-1;j++)
                dp[i] = max(dp[i], nums[i] + dp[j]), ans = max(ans, dp[i]);
        
        return ans;    
    }
};