#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    scanf("%d",&n);

    long long sum =0;
    for(int i=0;i<n;i++)
        scanf("%d",a+i),sum+= a[i];

    int ans = (sum%n ==0)? n : n-1;
    printf("%d\n",ans);
    return 0;
}
