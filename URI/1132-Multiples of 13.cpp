#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);

    if(n>m)
        swap(n,m);

    int res=0;

    for(int i=n;i<=m;i++){
        if(i%13)
            res+=i;
    }

    printf("%d\n",res);
    return 0;
}
