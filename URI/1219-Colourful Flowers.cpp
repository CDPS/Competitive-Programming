#include <bits/stdc++.h>

using namespace std;

int main(){


    int a,b,c;

    double pi=3.1415926535897;

    while(scanf("%d %d %d",&a,&b,&c)==3){

        double p = (a+b+c)/2.0;

        double aT= sqrt(p*(p-a)*(p-b)*(p-c));

        double r= sqrt( ((p-a)*(p-b)*(p-c))/p);

        double aC= pi*r*r;

        double R= (a*b*c)/(4.0*aT);

        double aTG= R*R*pi;

        printf("%.4lf %.4lf %.4lf\n",aTG-aT,aT-aC,aC);
    }

    return 0;
}
