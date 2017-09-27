#include <bits/stdc++.h>

using namespace std;

int main(){

    double a,b,c;

    double ar[3];
    for(int i=0;i<3;i++){
        scanf("%lf",ar+i);
    }
    sort(ar,ar+3);
    a = ar[2];
    b= ar[1];
    c=ar[0];


    if(a >= b+c)
        printf("NAO FORMA TRIANGULO\n");
    else {

    if( a*a == ( b*b)+(c*c) )
        printf("TRIANGULO RETANGULO\n");
    if(a*a > (b*b)+(c*c))
        printf("TRIANGULO OBTUSANGULO\n");
    if(a*a < (b*b) +(c*c))
        printf("TRIANGULO ACUTANGULO\n");
    if(a==b && a==c && c==b)
        printf("TRIANGULO EQUILATERO\n");
    else if(a==b || b==c || c==a)
        printf("TRIANGULO ISOSCELES\n");

    }


    return 0;
}
