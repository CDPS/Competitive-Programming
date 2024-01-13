class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int max = 0;
        int ans;
        int n  = nums.size();
        for(int i=0;i<n;i++){
            
            mp[nums[i]]++;
            if(mp[nums[i]] > max)
                max = mp[nums[i]], ans = nums[i];
        }

        return ans;
    }
};