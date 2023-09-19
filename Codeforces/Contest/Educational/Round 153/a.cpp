#include <bits/stdc++.h>

using namespace std;

bool isRegular(string s){
    return s.size()==2 && s[0]=='(' && s[1]==')';
}

int main(){

    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;

        if(isRegular(s)){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
            bool flag = false;
            for(int i=1;i<s.size();i++){
                if(s[i-1]== s[i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                 for(int i=0;i<s.size();i++){
                    cout<< "()";
                 }
                 cout << "\n";
            }else{

                 for(int i=0;i<s.size();i++){
                    cout<< "(";
                 }
                 for(int i=0;i<s.size();i++){
                    cout<< ")";
                 }
                 cout << "\n";
            }
        }
    }

    return 0;
}
