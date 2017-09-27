#include <bits/stdc++.h>

using namespace std;


int m = 40000;

int main(){

    int t,n;
    scanf("%d",&t);
    string s;

    long x = 0;
    bool f =1;

    while(t--){
        cin >> n >> s;

        if(x==0  && s[0]!='S'){
            f=0;
            break;
        }

        if(x== (m/2) && s[0]!='N'){
            f=0;
            break;
        }

        if(s[0]=='N'){
            x = ((n+x)%m) ;
        }

        if(s[0] =='S'){
            x = ((x+n) %m);
        }
    }

    if(f){
        if(x==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
