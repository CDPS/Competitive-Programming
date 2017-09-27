#include <bits/stdc++.h>

using namespace std;

int a[100];
int b[100];

int main(){
    int n,m;

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    for(int i=0;i<m;i++)
        scanf("%d",b+i);

    sort(a,a+n);
    sort(b,b+m);

    if(b[0] > max(a[0]*2,a[n-1]) ){
        printf("%d\n",max(a[0]*2,a[n-1]));
    }else{
        printf("-1\n");
    }

    return 0;
}
