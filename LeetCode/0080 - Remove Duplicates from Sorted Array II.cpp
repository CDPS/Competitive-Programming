class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[ nums[i] ] < 2)
                mp[ nums[i] ] ++;
        }

        int index =0;
        for(auto it = mp.begin();it !=mp.end();it++){
            for(int i=0;i<it->second;i++){
                nums[index] = it-> first;
                index++;
            }
        }

        return index;
    }
};