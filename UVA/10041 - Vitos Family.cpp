#include <bits/stdc++.h>

using namespace std;

int a[500];

int main(){

    int t,n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        int maxi=-1;
        for(int i=0;i<n;i++)
            scanf("%d",a+i), maxi=max(a[i],maxi);
        int res=15000000,sum;
        for(int i=1;i<=maxi;i++){
            sum=0;

            for(int j=0;j<n;j++)
                sum+= abs(i-a[j]);

            res = min(sum,res);
        }
        printf("%d\n",res);
    }
    return 0;
}
