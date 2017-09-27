#include <bits/stdc++.h>

using namespace std;

int main(){


    string line;

    while (getline(cin,line)!=NULL) {

        stack<char> s;

        for(int i=0;i<line.size();i++){

            if(line[i]=='('){
                 s.push(line[i]);
            }

            if(line[i]==')'){

                if(!s.empty())
                    s.pop();
                else{
                    s.push('(');
                    break;
                }
            }
        }

        if(s.empty())
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return 0;
}
