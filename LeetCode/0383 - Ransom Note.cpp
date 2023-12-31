class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int> rm;
        unordered_map<char, int> mm;

        for(int i=0;i<ransomNote.size();i++)
            rm[ ransomNote[i]]++;

        for(int i=0;i<magazine.size();i++)
            mm[ magazine[i]]++;

        for (auto it=rm.begin(); it!=rm.end(); it++){
            
            char letter = it-> first;
            int  quantity = it-> second;

            if (  !mm.count(letter) || mm[letter] < quantity)
                return false;
        }     

        return true;
    }
};
};