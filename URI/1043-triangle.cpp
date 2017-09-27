#include <bits/stdc++.h>

using namespace std;

int main(){

    double a,b,c;
    cin >> a >> b >> c;

    double  ia = abs(b-c);
    double ib = abs(a-c);
    double ic = abs(a-b);

    if( (ia< a && a < b+c)&& (ib< b && b < a+c) && (ic< c && c < b+a)){
        printf("Perimetro = %.1lf\n",a+b+c);
    }else{
        printf("Area = %.1lf\n", ( (a+b) *c )/2.0 );
    }
    return 0;
}
