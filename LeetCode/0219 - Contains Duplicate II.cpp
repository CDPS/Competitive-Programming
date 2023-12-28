class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, vector<int>> mp;
        
        int n= nums.size();
        for(int i=0;i<n;i++){
            mp[ nums[i] ].push_back(i);
            auto it = lower_bound(mp[ nums[i] ].begin(), mp[ nums[i] ].end(), i-k);
            if( *it !=i )
                return true;
        }
        return false;
    }
};