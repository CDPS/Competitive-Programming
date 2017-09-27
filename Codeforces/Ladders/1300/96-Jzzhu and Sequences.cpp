#include <bits/stdc++.h>

using namespace std;

#define m 1000000007

int main(){
    long a,b,n;
    scanf("%ld %ld %ld",&a,&b,&n);

    a = ( (a%m) + m)%m;
    b = ( (b%m) + m)%m;

    if( n%6==1){
        printf("%ld",a);
    }else if( n%6==2){
        printf("%ld",b);
    }else if ( n%6==3){
        printf("%ld", ( (b%m)-(a%m) +m)%m );
    }else if ( n%6==4){
        printf("%ld", ( ( (-1*a) %m) + m)%m );
    }else if ( n%6==5){
        printf("%ld", ( ( (-1*b) %m) + m)%m);
    }else{
         printf("%ld", ( (a%m)-(b%m) +m)%m );
    }
    return 0;
}
