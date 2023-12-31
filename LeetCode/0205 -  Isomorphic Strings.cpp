class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        unordered_map<char, int> ms;
        unordered_set<char> mt;
        
        for(int i=0;i<n;i++){
            if(!ms.count(s[i]) && mt.count(t[i]) )  return false;
            if(ms.count(s[i]) && ms[s[i]]!= t[i]) return false;
            ms[s[i]] = t[i];
            mt.insert(t[i]);
        }

        return true;
    }
};