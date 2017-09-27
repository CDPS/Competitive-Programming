#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){
        int n,m,r=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            if(m>0){
                r+=m;
            }
        }
        printf("Case %d: %d\n",caseno++,r);
        t--;
    }

    return 0;
}
