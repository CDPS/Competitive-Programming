#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){

        long long int n=1, raiz=1,x=1,y=1;

        scanf("%lld",&n);
        raiz = (long long)sqrtl(n);

        n= n-(raiz*raiz);

        if(n==0){
            n= 1+ 2*(raiz-1);
        }else{
            raiz++;
        }

        if(raiz%2==0 && n<=raiz){
            x=n;
            y=raiz;
        }

        if(raiz%2 &&n<=raiz ){
            x=raiz;
            y=n;
        }

        if (raiz%2==0 && n>raiz)
        {
            x = raiz;
            y = raiz - (n - raiz );
        }
        if (raiz%2 && n > raiz)
        {
            y=raiz;
            x = raiz - (n - raiz);
        }

        printf("Case %d: %lld %lld\n",caseno++,x,y);
        t--;
    }

    return 0;
}
