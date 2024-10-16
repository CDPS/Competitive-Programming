#include <bits/stdc++.h>

using namespace std;

bool isOp(char c){ return c=='[' || c=='(' || c=='{' || c=='<' || c==';';}
bool isCl(char c){ return c==']' || c==')' || c=='}' || c=='>' || c=='.';}

char f(char c){
    if(c==']') return '[';
    if(c==')') return '(';
    if(c=='}') return '{';
    if(c=='>') return '<';
    return ';';
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    char line[3001];

	while(gets(line)){

        vector<char> s;
        int len = strlen(line);

        for(int i=0;i<len;i++){
            if(line[i]== '(' && line[i+1]=='*') s.push_back(';'),i++;
            else if(line[i]== '*' && line[i+1]==')') s.push_back('.'),i++;
            else s.push_back(line[i]);
        }

        stack<char> st;
        int i;
        for(i=0; i<s.size();i++){
            if(isOp(s[i]))
                st.push(s[i]);
            else if(isCl(s[i])){
                if(!st.empty() && st.top()==f(s[i]))
                     st.pop();
                else{ break;}
            }
        }

        if(i < s.size() || !st.empty()) {
			cout << "NO " << i+1 << "\n";
		}else
			cout << "YES" << "\n";
    }
    return 0;
}
