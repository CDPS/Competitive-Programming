class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        nums.insert(nums.begin() , -1 );
        nums.push_back(INT_MIN);
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1] ){
                ans = i - 1;
                break;
            }
        }
        return ans;
    }
};