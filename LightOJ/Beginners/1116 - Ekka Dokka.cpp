#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){
        long long w,m=2,n=1;
        scanf("%lld",&w);

        if(w%2){
            printf("Case %d: Impossible\n",caseno++);
        }
        else{
            while(m<w){
                n=(long)w/(long)m;
                if(n%2){
                    printf("Case %d: %lld %lld\n",caseno++,n,m);
                    break;
                }
                m*=2;
            }
        }
        t--;
    }
    return 0;
}
