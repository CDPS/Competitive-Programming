class Solution {
public:

    int dp[2500];

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for(int i=0;i<n;i++) dp[i] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;    
    }
};