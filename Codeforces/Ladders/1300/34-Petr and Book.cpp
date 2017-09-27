#include <bits/stdc++.h>

using namespace std;

int a[7];

int main(){

    int n;
    scanf("%d",&n);

    int total=0;

    for(int i=0;i<7;i++)
        scanf("%d",a+i);

    int i=0;
    while(n>0){
        for(i=0;i<7;i++){
            if(a[i]>=n){
               printf("%d\n",i+1);
               return 0;
            }else{
                n-=a[i];
            }
        }
    }

    return 0;
}
