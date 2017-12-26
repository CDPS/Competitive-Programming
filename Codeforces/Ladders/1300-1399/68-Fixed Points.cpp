#include <bits/stdc++.h>

using namespace std;

int a[100000],v[100000];
int n;

int main(){

    scanf("%d",&n);

    int idx;

    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        v[ a[i] ]=i;
    }

    int ans =0;
    for(int i=0;i<n;i++) if(a[i]==i) ans++;

    int r=0;
    for(int i=0;i<n;i++){
        if(a[i]!=i){
            idx = v[i];
            int p=0;
            if(idx==a[i]) p= 2;
            else p=1;
            r = max(r,p);
        }
    }
    printf("%d\n",ans+r);
    return 0;
}
