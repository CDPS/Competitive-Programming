class Solution {
public:

    int countWords(string str)
    {
        stringstream s(str); 
        string word; 
        int count = 0;
        while (s >> word)
            count++;
        return count;
    }

    bool wordPattern(string pattern, string s) {
        
        if(countWords(s) !=pattern.size())
            return false;
        
        unordered_map<char, string>  mp1;
        unordered_map<string, char> mp2;

        string word; 
         
        stringstream stream(s); 
        stream >> word;
        
        mp1[pattern[0] ] = word ;
        mp2[word] = pattern[0]  ;
        
        for(int i=1;i<pattern.size();i++){
            stream >> word;
            if(mp1.count(pattern[i])){
                if( mp1[pattern[i]] != word )
                    return false;
            }else{

                if(mp2.count(word))
                    return false;
                
                mp1[pattern[i] ] = word ;
                mp2[word] = pattern[i]  ;
            }
        }

        return true;
    }
};