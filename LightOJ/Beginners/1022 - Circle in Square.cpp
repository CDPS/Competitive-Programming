#include <stdio.h>
#include <math.h>
#define pi 2*acos (0.0)
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){
        double n,r=0;
        scanf("%lf",&n);
        double sq= (n*2)*(n*2),sc=pi*(n*n);
        r=sq-sc;
        printf("Case %d: %.2f\n",caseno++,r);
        t--;
    }
    return 0;
}
