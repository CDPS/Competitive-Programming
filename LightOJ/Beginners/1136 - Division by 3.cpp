#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t--){
        long a,b,r,suma,sumb;
        scanf("%ld %ld",&a,&b);

        suma=(a==1)? 0: 2*(a-1)/3;
        sumb=2*b/3;
        r=sumb-suma;
        printf("Case %d: %ld\n",caseno++,r);
    }
    return 0;
}
