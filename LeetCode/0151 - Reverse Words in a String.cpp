class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s); 
        string word, ans;
        ss >> ans;
        while(ss >> word)
            ans= word + " " + ans;
        return ans;
    }
};