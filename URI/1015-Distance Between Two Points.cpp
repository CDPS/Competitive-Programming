#include <bits/stdc++.h>

using namespace std;


int main(){

    double x1,y1,x2,y2;

    cin >> x1 >> y1;

    cin >> x2 >> y2;

    double r1 = x2-x1;
    double r2= y2-y1;

    double res = sqrt(r1*r1 + r2*r2);
    printf("%.4lf\n",res);
    return 0;
}
