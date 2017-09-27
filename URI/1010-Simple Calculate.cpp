#include <bits/stdc++.h>

using namespace std;

int main(){

    int c1,u1,c2,u2;
    double p1, p2;

    cin >> c1 >> u1 >> p1;
    cin >> c2 >> u2 >> p2;

    printf("VALOR A PAGAR: R$ %.2lf\n",( (double)u1 )*p1 + ( (double)u2 )*p2 );
    return 0;
}
