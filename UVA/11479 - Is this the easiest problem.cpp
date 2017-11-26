#include <bits/stdc++.h>

using namespace std;

long a[3];

int main(){
    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%ld %ld %ld",a+0,a+1,a+2);
        sort(a,a+3);

        if( (a[0]+a[1] > a[2]) && (a[0]+a[2]>a[1]) && (a[1]+a[2]>a[0]) && a[0]>0 && a[1]>0 &&a[2]>0){

            if(a[0]==a[1]&&a[1]==a[2]){
                printf("Case %d: Equilateral\n",caseno++);
            }
            else if(a[0]==a[1]||a[1]==a[2]){
                printf("Case %d: Isosceles\n",caseno++);
            }else{
                printf("Case %d: Scalene\n",caseno++);
            }
        }
        else{
            printf("Case %d: Invalid\n",caseno++);
        }
    }
    return 0;
}
