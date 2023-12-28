class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, vector<int> > mp;
        int x =0, y=0;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back( i );
            if(mp.find(target-nums[i]) != mp.end() ){
                x = i;
                for(int j=0;j<mp[ target-nums[i] ].size(); j++){
                    if(mp[target-nums[i]][j] !=i){
                         y = mp[target-nums[i]][j];
                         return {x,y};
                    }
                }
            }
        }
        
        return {x,y};
    }
};