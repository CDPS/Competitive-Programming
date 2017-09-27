#include <stdio.h>
#include <math.h>
#define TAMAGNOVECTOR 1000001
using namespace std;

double  fac[TAMAGNOVECTOR];
int main() {

    fac[0]=1;
    double faci=0;

    for(int i=1;i<=TAMAGNOVECTOR;i++){
        faci+=log(i);
        fac[i]=faci;
    }

    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){

        long r,n,b;
        scanf("%ld %ld",&n,&b);
        r= (long )(fac[n]/log(b) +1);
        printf("Case %d: %ld\n",caseno++,r);
        t--;
    }
    return 0;
}
