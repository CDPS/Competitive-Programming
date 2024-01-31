class Solution {
public:

    bool isOperator(string op){
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    void evaluate(stack<int> &st, string op){
        int value1= st.top(); st.pop();
        int value2= st.top(); st.pop();
        if(op == "+") st.push(value2 + value1);
        if(op == "-") st.push(value2 - value1);
        if(op == "*") st.push(value2 * value1);
        if(op == "/") st.push(value2 / value1);
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i]))
                evaluate(st,tokens[i]);
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};