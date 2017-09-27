#include <bits/stdc++.h>

using namespace std;


int main(){


     int t;
    scanf("%d",&t);

    while(t--){

        long n;
        scanf("%ld",&n);

        if(n==0){
            printf("NULL\n");

        }else if(n>0){

            if(n%2==0)
                printf("EVEN POSITIVE\n");
            else
                printf("ODD POSITIVE\n");

        }else{

            n*=-1;
            if(n%2==0)
                printf("EVEN NEGATIVE\n");
            else
                printf("ODD NEGATIVE\n");
        }


    }
    return 0;
}
