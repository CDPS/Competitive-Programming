#include <bits/stdc++.h>

using namespace std;


double t[1000];
int main(){

    int x,y;
    scanf("%d %d",&x,&y);

    int n;
    scanf("%d",&n);

    int xi,yi,v;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&xi,&yi,&v);

        double dis= sqrt( ( (xi-x)*(xi-x) ) + ( (yi-y)*(yi-y) ) );
        t[i]= dis/(double)v;
    }
    sort(t,t+n);

    printf("%lf\n",t[0]);

    return 0;
}
