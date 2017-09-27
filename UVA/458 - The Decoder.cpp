#include <bits/stdc++.h>

using namespace std;

int main(){

    string s,r;
    while(getline(cin,r)){
        s="";
        for(int i=0;i<r.size();i++){
            s+= r[i]-7;
        }
        cout << s << "\n";
    }
     return 0;
}
