#include <bits/stdc++.h>

using namespace std;


int a[100];
int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    int mini=1000000;
    int j=0;

    for(int i=0;i<n;i++){
        if(mini>=a[i]){
            j=i;
            mini=a[i];
        }
    }

    int res=0;
    for(int i=j;i<n-1;i++){
        swap(a[i],a[i+1]);
        res++;
    }

    j=0;
    int maxi =0;
    for(int i=0;i<n;i++){
        if(maxi< a[i]){
            j=i;
            maxi=a[i];
        }
    }

    res+=(j);
    printf("%d\n",res);
    return 0;
}
