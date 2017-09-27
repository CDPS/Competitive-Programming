#include <bits/stdc++.h>

using namespace std;
int main(){

    int n;
    scanf("%d",&n);

    long a[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }

    long mi,ma;
    mi = abs(a[0]-a[1]);
    ma = abs(a[n-1]-a[0]);
    printf("%ld %ld\n",mi,ma);

    long min1,min2;
    long max1,max2;

    for(int i=1;i<n-1;i++){
        min1 =  abs(a[i-1]-a[i]);
        min2 =  abs(a[i+1]-a[i]);
        max1 =  abs(a[0]-a[i]);
        max2 =  abs(a[n-1]-a[i]);

        mi = (min1<min2)? min1: min2;
        ma = (max1>max2)? max1:max2;
        printf("%ld %ld\n",mi,ma);
    }

    mi = abs(a[n-1]-a[n-2]);
    ma = abs(a[n-1]-a[0]);

    printf("%ld %ld\n",mi,ma);

    return 0;
}
