#include <bits/stdc++.h>

using namespace std;

int main(){

    string r,s="";
    bool f =1;

    while(getline(cin,r)){
        for(int i=0;i<r.size();i++){
            if(r[i]=='"'){
                if(f)
                    s+="``",f=0;
                else
                    s+="''",f=1;
            }else{
                s+=r[i];
            }
        }
        s+="\n";
    }
    cout << s;

    return 0;
}
