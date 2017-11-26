#include <bits/stdc++.h>

using namespace std;

double a[1000];

int main(){

    int n;
    while(scanf("%d",&n) && n){

        double prom = 0.0;
        for(int i=0;i<n;i++)
            scanf("%lf",a+i), prom+=a[i];
        sort(a,a+n);
        prom = prom/double(n);

        double ans =0.0;
        for(int i=0;i<n && a[i]<prom;i++)
            ans = ans + (prom-a[i]);
        printf("$%.2lf\n",ans);
    }
    return 0;
}
