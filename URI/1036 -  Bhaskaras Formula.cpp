#include <bits/stdc++.h>

using namespace std;

int main(){

    double a,b,c;

    cin >> a >> b >> c;

    double i = b*b;
    double d = 4.0*a*c;

    if(i < d || a==0)
        printf("Impossivel calcular\n");
    else{

        double r1 = ( (b*-1)+sqrt(i-d))/(2*a);
        double r2 = ( (b*-1)-sqrt(i-d))/(2*a);

        printf("R1 = %.5lf\n",r1);
        printf("R2 = %.5lf\n",r2);
    }

    return 0;
}
