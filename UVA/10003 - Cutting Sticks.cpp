#include <bits/stdc++.h>

using namespace std;

int l,n,c[50];

int main(){

    while(scanf("%d",&l) && l){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",c+i);
        int ans=l;
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
