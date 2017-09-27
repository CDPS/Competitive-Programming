#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);

    long res=1;
    for(int i=1;i<=n;i++){
        res*=i;
    }
    printf("%ld\n",res);
    return 0;
}
