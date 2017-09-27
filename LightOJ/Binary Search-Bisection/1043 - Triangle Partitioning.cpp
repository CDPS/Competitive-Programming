#include <bits/stdc++.h>
 
using namespace std;
 
double aA,aB,aC,area;
 
 
double binarySearch(double mini, double maxi,double t){
 
    double med = (maxi+mini)/2.0;
    double c = med;
 
    int te=100;
    while(te--){
 
        double b = (c*sin(aB))/sin(aC);
        double a = ((b*sin(aA))/sin(aB));
 
        double p = (b+a+c)/2.0;
        double subarea1= sqrt(p*(p-b)*(p-a)*(p-c));
        double subarea2= area - subarea1;
 
        if( subarea1/subarea2 ==t)
            break;
 
        if(subarea1<  subarea2*t){
            maxi = med;
            med=(maxi-mini)/2.0 + mini;
            c+=(maxi-mini)/2.0 ;
        }
        else{
            mini=med;
            med=(maxi-mini)/2.0 + mini;
            c-=(maxi-mini)/2.0 ;
        }
    }
 
    return c;
}
 
int main(){
    int t,caseno=1;
 
    scanf("%d",&t);
 
 
    while(t--){
 
        double ab,ac,bc,r;
 
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&r);
 
        aA = acos( ((bc*bc)+(ab*ab)-(ac*ac) )/(2.0*bc*ab));
        aB = acos( ((ac*ac)+(ab*ab)-(bc*bc) )/(2.0*ac*ab));
        aC = acos( ((ac*ac)+(bc*bc)-(ab*ab) )/(2.0*ac*bc));
 
        double b = (ab*sin(aB))/sin(aC);
        double a = ((b*sin(aA))/sin(aB));
 
        double p = (ab+ac+bc)/2.0;
        area= sqrt(p*(p-ab)*(p-bc)*(p-ac));
 
        double ans = binarySearch(0,ab,r);
 
        printf("Case %d: %lf\n",caseno++,ans);
    }
    return 0;
}
