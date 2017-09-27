#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,l,h,w,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&l,&w,&h);
        if(l>20 || w>20 || h>20)
           printf("Case %d: bad\n",caseno++);
        else
            printf("Case %d: good\n",caseno++);
    }
    return 0;
}
