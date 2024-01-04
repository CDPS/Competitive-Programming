class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map<string,int> mp, curr;
        
        for(int i=0;i<words.size();i++)
            mp[ words[i] ]++;
        
        int l=words[0].length();
        int n=s.length()- (words.size()*l);
        if(n<0)
            return {};

        vector<int> ans;
        for(int i=0;i<=n;i++) {
            curr=mp;
            int c=0;
            for(int j=i;j<s.size();j+=l) {
                string x=s.substr(j,l);
                if(curr[x]>0) c++, curr[x]--;
                else break;
            }
            if(c==words.size()) ans.push_back(i);
        }

        return ans;
    }
};