#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);

    int u,v;
    scanf("%d %d",&u,&v);

    int on= v-u; int maxi=v-u;

    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        on= on - u + v;
        maxi=max(maxi,on);
    }

    printf("%d",maxi);
    return 0;
}
