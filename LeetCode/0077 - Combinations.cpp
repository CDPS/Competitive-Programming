class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(int n, int k, int current, int index, vector<int> &acc){
        
        if(current > k){ 
             ans.push_back(acc); 
             return; 
        }

        for(int i = index; i <= n;i++){
            acc.push_back(i);
            backtrack(n,k, current + 1, i +1, acc);
            acc.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> partial;
        backtrack(n,k, 1, 1, partial);
        return ans;
    }
};