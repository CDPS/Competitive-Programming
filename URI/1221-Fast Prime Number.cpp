#include <bits/stdc++.h>

using namespace std;

int main(){

    int c;
    scanf("%d",&c);

    while(c--){

        long n;
        scanf("%ld",&n);

        bool r=true;

        if (n == 2 ){
            r= true;
        }
        else if (n%2 == 0){
            r=false;
        }
        else{

            long m=sqrt(n);
            for (long i = 3; i <= m; i+=2){
                if (n%i == 0){
                    r=false;
                    break;
                }
            }
        }


        if(r){
            printf("Prime\n");
        }
        else{
            printf("Not Prime\n");
        }

    }
    return 0;
}
