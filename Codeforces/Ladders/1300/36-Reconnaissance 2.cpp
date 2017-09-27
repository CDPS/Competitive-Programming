#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }

    int mini=100001;

    int i1,i2;
    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1]) < mini ){
            mini= abs(a[i]-a[i+1]);
            i1=i;
            i2=i+1;
        }
    }

    if(abs(a[0]-a[n-1]) < mini){
        i1=0;
        i2=n-1;
    }

    printf("%d %d\n",i1+1,i2+1);
    return 0;
}
