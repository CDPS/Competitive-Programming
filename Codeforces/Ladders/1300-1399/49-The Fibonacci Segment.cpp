#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",a+i);

    if(n<=2){
        printf("%d\n", n);
    }else{

        int maxi = 2, acc =2;

        for(int i=2;i<n;i++){
            if(a[i]==a[i-1]+a[i-2]){
                acc++;
            }else{
                maxi = max(maxi,acc);
                acc=2;
            }
        }

        maxi = max(maxi,acc);
        printf("%d\n",maxi);
    }
    return 0;
}
