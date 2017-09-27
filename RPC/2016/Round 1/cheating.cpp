#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, x, y,res=0;
    long x2=0, y2=0;
    double dis=0;
    long d;
    scanf("%d",&t);

   while(t--){
        scanf("%ld %d %d",&d, &x, &y);
        x2 = x*x;
        y2 = y*y;
        dis = sqrt(x2+y2);
        res = ceil(double(dis)/double(sqrt(double(d))));
        printf("%d\n",res);
    }
    return 0;
}
