#include <stdio.h>
#include <math.h>
#define pi 2*acos (0.0)

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    int caseno=1;
    while(t){
        double R,r=0,angulo;
        int n;
        scanf("%lf %d",&R,&n);
        angulo=(double)(pi)/(double)(n);
        r=(double)R/(double)( (1/sin(angulo))+1);
        printf("Case %d: %f\n",caseno++,r);
        t--;
    }
    return 0;
}
