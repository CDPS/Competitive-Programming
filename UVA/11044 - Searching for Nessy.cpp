#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        int r1= ( (n-2)/3 ); r1 = ((n-2)%3==0)? r1 : r1+1;
        int r2=  ( (m-2)/3 );r2 = ((m-2)%3==0)? r2 : r2+1;
        printf("%d\n",r1*r2);
    }
    return 0;
}
