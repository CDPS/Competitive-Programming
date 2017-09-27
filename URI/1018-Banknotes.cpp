#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);

    int a[6]={5,2,1,5,2,1};
    int b[6]={50,20,10,5,2,1};
    int res[6]={0,0,0,0,0,0};
    int m=n;

    int d1 = n%10;
    n/=10;

    int d2 = n%10;
    n/=10;
    int d3 = n;


    int i=0;
    while(d2!=0){
        if(d2 >=a[i]){
            d2-=a[i];
            res[i]++;
        }
        else{
            i++;
        }
    }

    i=3;
     while(d1!=0){
        if(d1 >=a[i]){
            d1-=a[i];
            res[i]++;
        }
        else{
            i++;
        }
    }

    printf("%d\n",m);
    printf("%d nota(s) de R$ 100,00\n",d3);
    for(int i=0;i< 6;i++){
        printf("%d nota(s) de R$ %d,00\n",res[i],b[i]);
    }

    return 0;
}
