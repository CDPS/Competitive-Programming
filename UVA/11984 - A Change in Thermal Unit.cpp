#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    double c,i;
    while(t--){
        scanf("%lf %lf",&c,&i);
        printf("Case %d: %.2lf\n",caseno++,c + ( 5.0*(i/9.0) ) );
    }
    return 0;
}
