class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]== val)
                nums[i] = 100000, ans ++;
        
        sort(nums.begin(), nums.end());
        return n - ans;
    }
};