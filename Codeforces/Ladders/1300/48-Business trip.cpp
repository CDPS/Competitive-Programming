#include <bits/stdc++.h>

using namespace std;


int a[12];
int main(){

    int k;
    scanf("%d",&k);
    for(int i=0;i<12;i++)
        scanf("%d",a+i);
    sort(a,a+12);

    int res=0;
    int acc=0;

    for(int i=11;i>=0;i--){
        if(acc+a[i]>=k){ acc+=a[i];res++;break;};
        acc+=a[i];res++;
    }

    if(k==0)printf("0\n");
    else if(res==12 && acc<k)printf("-1\n");
    else printf("%d\n",res);
    return 0;
}
