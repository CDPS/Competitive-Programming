#include <bits/stdc++.h>


using namespace std;

int main(){

    string n;

    while(cin >> n){


        while(n[n.size()-1]!='#'){

            string s;
            cin >>s;
            n+=s;
        }

        long long res=0;
        long long r=1;
        for(int i=n.size()-2;i>=0;i--){

            if(n[i]=='1'){
                res =  (res%131071) + r;
                r = (r%131071) *2;
                r%=131071;

            }else{
                r = (r%131071) *2;
                r%=131071;
            }
        }

        res%=131071;

        if(res==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
