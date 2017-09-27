#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    int caseno=1;
    while(t){
        int r,n,b,d;
        scanf("%d %d",&n,&b);
        d =(b>n)?b-n:n-b;
        r = (d)*4 +11 + (n*4) +8;
        printf("Case %d: %ld\n",caseno++,r);
        t--;
    }
    return 0;
}
