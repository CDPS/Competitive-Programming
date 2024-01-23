class Solution {
public:

    bool isOpen(char c){
        return c == '(' || c == '[' || c == '{';
    }

    bool valiClose(char o, char c){
        if(c == ')' )
           return o == '('; 
        if(c== ']') 
            return o == '['; 
        return o == '{';
    }

    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(isOpen(s[i]))
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                if(!valiClose(st.top(),s[i])) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};