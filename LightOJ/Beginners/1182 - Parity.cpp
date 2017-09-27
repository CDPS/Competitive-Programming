#include <stdio.h>
#include <math.h>
using namespace std;

long bits(long i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main() {
    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t--){
        long a,r;
        scanf("%ld",&a);

        r=bits(a);
        if(r%2){
            printf("Case %d: odd\n",caseno++);
        }else{
            printf("Case %d: even\n",caseno++);
        }
    }
    return 0;
}
