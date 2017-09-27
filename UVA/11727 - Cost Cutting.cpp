#include <bits/stdc++.h>

using namespace std;

int a[3];
int main(){
    int t, caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        printf("Case %d: %d\n",caseno++,a[1]);
    }
    return 0;
}
