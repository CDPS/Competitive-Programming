class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;

        map<char, int> ms;
        unordered_map<char, int> mt;
        
        int n = s.size();
        for(int i=0;i<n;i++)
            ms[s[i]] ++, mt[t[i]]++;
        
        for(auto it= ms.begin();it != ms.end(); it++){
            if( !mt.count( it->first) || mt[it->first]  != it->second)
                return false;
        }

        return true;
    }
};