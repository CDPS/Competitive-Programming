class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n =s.size();
        int ans = -1;
        unordered_set<char> st;
        
        for(int i=0,j =0;i<n;i++){
            while(st.find( s[j]) == st.end() && j < n )
                st.insert(s[j++]);
            ans = max(ans, j-i);
            st.erase(s[i]);
        }

        return ans == -1 ? 0 : ans;
    }
};