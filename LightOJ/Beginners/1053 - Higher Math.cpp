#include <stdio.h>
#include <math.h>
#define pi 2*acos (0.0)
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    int caseno=1;
    while(t){

        long long a,b,c;
        double  resa,resb, resc;
        scanf("%lld %lld %lld",&a,&b,&c);

        resa = acos( (double)((b*b) + (c*c) - (a*a))/(double)(2*b*c));
        resb = acos( (double)((a*a) + (c*c) - (b*b))/(double)(2*a*c));
        resc = acos( (double)((a*a) + (b*b) - (c*c))/(double)(2*a*b));

        if(resa==pi/2|| resb==pi/2|| resc==pi/2){
            printf("Case %d: yes\n",caseno++);
        }else{
            printf("Case %d: no\n",caseno++);
        }
        t--;
    }
    return 0;
}
