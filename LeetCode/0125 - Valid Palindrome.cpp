class Solution {
public:
    bool isPalindrome(string s) {

        string salphanumeric = "";

        for(int i=0;i<s.size();i++)
            if(iswalnum(s[i]))
                 salphanumeric+= tolower(s[i]);

        int n = salphanumeric.size()%2 ? salphanumeric.size()/2 +1 : salphanumeric.size()/2;
       
        for(int i=0;i<n;i++){
            if(salphanumeric[i] != salphanumeric[ salphanumeric.size()-i-1])
                return false;
        }
        return true;       
    }
};