#include <bits/stdc++.h>

using namespace std;

int p,q,r,s,t,u;

double f(double  x){ return (p*exp(x*-1)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u; }

//bisection method
double binarySearch(){

    double l=0, h=1,m;

    int t=100;
    while(t--){
        m = (l+h)/2;
        if( f(m) * f(l) > 0 )
            l = m;
        else
            h=m;
    }
    return m;
}

int main(){

    while(cin >> p>> q >> r >> s >> t >>u){
        if(f(0)*f(1) <= 0.0 )
            printf("%.4lf\n", binarySearch());
        else
            printf("No solution\n");
    }
    return 0;
}
