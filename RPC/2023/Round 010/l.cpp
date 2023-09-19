#include <bits/stdc++.h>

using namespace std;

int main(){

    string s,t;
    cin >> s;

    int c = 0;
    set<string> st;
    vector<string> a;
    for(int i = 0;i<s.size();i++){
         t+=s[i];

         if(s[i]=='(')
                c++;
         else
            c--;

         if(c==0){
            a.push_back(t);
            st.insert(t);
            t="";
         }
    }

    if(st.size()==1){
        cout << "no" << "\n";
    }
    else{
        for(int i = 1;i<a.size();i++){
            cout << a[i];
        }
        cout << a[0] << "\n";
    }
    return 0;
}
