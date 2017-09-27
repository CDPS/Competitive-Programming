#include <bits/stdc++.h>

using namespace std;

long long a[100001];

int main(){

    int n;long long s;

    while(scanf("%d %lld",&n,&s)==2){

        a[0]=0;
        for(int i=1;i<=n;i++){ scanf("%lld",a+i); a[i]+= a[i-1];}

        bool f =0;
        for(int i=1;i<=n && !f ;i++){
            for(int j=i;j<=n && !f;j++){
                if(a[j]-a[i-1]==s)
                    printf("%d %d\n",i,j).f=1;
                else if(a[j]-a[i-1]>s) break;
            }
        }
        if(!f) printf("-1\n");
    }
    return 0;
}
