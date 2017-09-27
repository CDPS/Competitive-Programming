#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i]!='1' && s[i]!='4'){
            printf("NO\n");
            return 0;
        }
    }

    if(s[0]=='4'){
        printf("NO\n");
        return 0;
    }

    for(int i=0;i<s.size();i++){
        if(s[i]=='4'){
            int res=0;
            while(s[i]=='4'){
                i++;
                res++;
            }
            if(res>2){
                 printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    return 0;
}
