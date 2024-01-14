class Solution {
public:
    int lengthOfLastWord(string str) {
        stringstream s(str); 
        string word; 
        while (s >> word){}
        return word.size();
    }
};