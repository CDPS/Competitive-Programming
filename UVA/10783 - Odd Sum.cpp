#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,l,h,res=0,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&l,&h);
        res=0;
        for(int i=l;i<=h;i++)if(i%2)res+=i;
        printf("Case %d: %d\n",caseno++,res);
    }

    return 0;
}
