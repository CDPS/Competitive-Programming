#include <bits/stdc++.h>

using namespace std;


int main(){

    long n;

    while(scanf("%ld",&n)==1){

        long long r=1;
        int res =1;

        while(r!=0){
            r = ((r%n) * (10%n) )%n ;
            r =  (r%n + 1)%n;
            res++;
        }

        printf("%ld\n",res);
    }

    return 0;
}
