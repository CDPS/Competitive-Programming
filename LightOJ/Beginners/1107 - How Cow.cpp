#include <stdio.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){
        int x1,y1,x2,y2,m,xi,yi;

        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d", &m);
        printf("Case %d:\n",caseno++);
        while(m){
            scanf("%d %d",&xi,&yi);

            if(x1<xi && xi<x2 && y1<yi && yi<y2){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
            m--;
        }
        t--;
    }
    return 0;
}
