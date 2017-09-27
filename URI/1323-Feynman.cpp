#include <bits/stdc++.h>

using namespace std;

long a[101];
int main(){

    a[0]=0;
    for(int i=1;i<101;i++){
        a[i]= i*i + a[i-1];
    }

    int n;
    scanf("%d",&n);
    while(n!=0){

        printf("%d\n",a[n]);

        scanf("%d",&n);
    }

    return 0;
}
