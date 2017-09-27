#include <bits/stdc++.h>

using namespace std;


int main(){


    long long n,m;

    while(true){

        scanf("%lld %lld",&n,&m);

        if(n==0 && m==0){
            break;
        }

        if(m>n){
            swap(n,m);
        }
        int  mi=0,ni=0;

        int res= 0;
        bool c=false;

        while(n>0){

            mi=m%10;
            ni=n%10;

            if(c)mi++;

            if(mi+ni>=10){
                res++;
                c=true;
             }else{
                c= false;
             }

            n/=10;
            m/=10;
        }


        if(res==0){
            printf("No carry operation.\n");
        }else if(res==1){
            printf("%d carry operation.\n",res);
        }
        else{
            printf("%d carry operations.\n",res);
        }
    }

    return 0;
}
