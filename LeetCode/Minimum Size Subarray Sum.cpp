class Solution {
public:
    int oo = 100001;
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n   = nums.size();
        int acc = 0;
        int ans = oo;

        for(int i =0, j = 0;i<n;i++){
            
            while(acc < target && j < n)
                acc += nums[j++];
            
            if(acc >= target)
                ans = min(ans, (j-i)) ;

            acc-=nums[i];
        }

        return ans==oo? 0: ans ;
    }
};