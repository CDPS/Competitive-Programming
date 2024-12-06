#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    int ans = 0;
    set<pair<int,int>> st;
    for(int i=0;i<s.size() - 4;i++){
        if(s[i]== 'b' && s[i+1]== 'e' && s[i+2]== 'a' && s[i+3]== 'r'){
            for(int j=0;j<=i;j++)
                st.insert({j,i+3}), cout << j+1 << " " << i + 4 << "\n";
            for(int j=i+3;j<s.size();j++)
                st.insert({i,j}), cout << i+1 << " " << j + 1 << "\n";
        }
    }

    cout << st.size() << "\n";
    return 0;
}
