class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l = 0, h = numbers.size()-1;
        while(l < h){
            if(numbers[l] + numbers[h] == target)
                break;
            else if(numbers[l] + numbers[h] > target )
                h--;
            else
                l++;
        }
        return {l+1, h +1};
    }
};