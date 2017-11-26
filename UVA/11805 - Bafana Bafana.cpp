#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    int n,k,p;
    while(t--){
        scanf("%d %d %d",&n,&k,&p);
        int r = ((k%n)+(p%n))%n;
        printf("Case %d: %d\n",caseno++, (r==0)?n:r );
    }
    return 0;
}
