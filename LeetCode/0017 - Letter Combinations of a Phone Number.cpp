class Solution {
public:

    vector<string> keyboard = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void backtrack(string digits, int index, string acc ,vector<string> &ans){
        
        if(index == digits.size()){
            ans.push_back(acc); return;
        }
            
        string key = keyboard[  digits[index]-'0' ];
        for(int i=0;i< key.size();i++){
            backtrack(digits, index + 1, acc + key[i], ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        backtrack(digits,0,"",ans);
        return ans;
    }
};