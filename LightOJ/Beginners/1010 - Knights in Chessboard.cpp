#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){

        int n,m,r=0;
        scanf("%d %d",&m,&n);

        if(m==1||n==1){
            r=max(m,n);
        }
        else if(m==2||n==2){
            int i = max(m,n);
            if(i%4==1){
                r=(4*(i/4))+2;
            }else if(i%4==0){
                r=(i/4)*4;
            }else{
                r=(i/4)*4 +4;
            }
        }
        else{
            if(n%2){
                r=((n*m)+1)/2;
            }else{
                r=(n*m)/2;
            }
        }
        printf("Case %d: %d\n",caseno++,r);

        t--;
    }

    return 0;
}
