#include <bits/stdc++.h>

using namespace std;

int a[50];

int main(){
    int t,n,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int h=0,l=0;
        for(int i=0;i<n-1;i++){
            if(a[i+1]>a[i]) h++;
            if(a[i+1]<a[i]) l++;
        }
        printf("Case %d: %d %d\n",caseno++,h,l);
    }
    return 0;
}
