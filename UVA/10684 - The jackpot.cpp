#include <bits/stdc++.h>

using namespace std;

int a[10001], s[10001];

int main(){

    int n;
    while(scanf("%d",&n) && n){

        s[0]=a[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),s[i]= a[i] + a[i-1];

        int maxi = 0;

        for(int i=1;i<=n;i++){
             s[i] = max(a[i],a[i]+s[i-1]);
             maxi = max(maxi,s[i]);
        }

        if(maxi==0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",maxi);
    }
    return 0;
}
