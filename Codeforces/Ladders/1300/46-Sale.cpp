#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);

    int res=0;
    for(int i=0;i<m;i++){
        if(a[i]>=0)break;
        res+= (a[i]*-1);
    }

    printf("%d\n",res);
    return 0;
}
