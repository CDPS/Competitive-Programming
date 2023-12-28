class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it= mp.begin(); it!= mp.end();it++)
            ans.push_back(it->second);
        return ans;
    }
};