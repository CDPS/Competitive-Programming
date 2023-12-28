class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        map<int, int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]] = i;

        vector< vector<int>> answer;
        for(int i=0;i<n;i++){
            
             if (i != 0 && nums[i] == nums[i - 1]) continue;
             if (nums[i] > 0) return answer;

            for(int j=i+1;j<n;j++){

                if (j != i + 1 && nums[j] == nums[j - 1]) continue;

                int sum = nums[i] + nums[j];
                map<int,int>::iterator search = mp.find(sum * -1);
                
                if( search != mp.end() &&  search->second > j ){                    
                    answer.push_back({  nums[i] , nums[j], nums[search->second]  });
                }
            }
        }
        return answer;
    }
};