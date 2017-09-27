#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,caseno=1;
    while(scanf("%d",&n) && n>0){
        int r =1,ans=0;
        while(r<n)r*=2,ans++;
        printf("Case %d: %d\n",caseno++,ans);
    }
    return 0;
}
