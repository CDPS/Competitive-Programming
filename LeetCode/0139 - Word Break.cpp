class Solution {
public:

    bool dp [301];

    bool wordBreak(string s, vector<string>& words) {
        
        dp[0] = 1;
        int n = s.size(), m = words.size();
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                int ws =  words[j].size();
                if(i-ws<0) continue;               
                if(s.substr(i - ws, ws)==words[j] && dp[i- ws])
                    dp[i] = true ;
            }
        }
        return dp[s.size()];    
    }
};