#include <bits/stdc++.h>

using namespace std;

long a[10001];

void preCalc(){

    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<=10000;i++)
        a[i] = a[i-1] + 3;
}

int main(){

    preCalc();
    int t,n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        printf("%ld\n",a[n]);
    }
    return 0;
}
