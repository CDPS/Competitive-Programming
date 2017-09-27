#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,r;
    int res;

    while(getline(cin, s)){

        res=0;
        bool f =1;
        for(int i=0;i<s.size();i++){
            if( ( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ) ){
                if(f){
                    res++;
                    f=0;
                }
            }else{ f=1; }
        }
        cout << res << "\n";
    }
    return 0;
}
