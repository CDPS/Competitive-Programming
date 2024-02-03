class Solution {
public:

    void backtrack(vector<string>& ans, string acc, int o, int c)
    {
        if(o == 0 && c == 0) {
            ans.push_back(acc);
            return;
        }
        if(o > 0) backtrack(ans,acc + '(',o-1,c);
        if(c > o) backtrack(ans,acc + ')',o,c-1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans,"",n,n);
        return ans;
    }
};