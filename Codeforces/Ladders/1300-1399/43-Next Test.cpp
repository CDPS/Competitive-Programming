#include <bits/stdc++.h>

using namespace std;

int a[3001];

int main(){

    for(int i=0;i<=3000;i++) a[i]=0;
    int n,x,mini=3001;

    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&x),a[x]=1;

    for(int i=1;i<3001;i++) if(!a[i]){mini=i;break;}

    printf("%d\n",mini);
    return 0;
}
