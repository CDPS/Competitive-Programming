#include <bits/stdc++.h>

using namespace std;


int a[1000];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    int mini=a[0],maxi= a[0], res=0;

    for(int i=1;i<n;i++){
        if(a[i]<mini){ mini=a[i];res++;}
        if(a[i]>maxi){ maxi=a[i];res++;}
    }

    printf("%d\n",res);
    return 0;
}
