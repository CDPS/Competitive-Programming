#include <bits/stdc++.h>

using namespace std;

int main() {

    int t,caseno=1;

    scanf("%d",&t);

    while(t--){
        int ax,ay,bx,by,cx,cy;
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);

        int px= ax-bx;
        int py=ay-by;
        int qx= cx-bx;
        int qy= cy-by;

        int area = abs(px*qy - py*qx);

        int x= ax+qx;
        int y= ay+qy;

        printf("Case %d: %d %d %d\n",caseno++,x, y,area);
    }
    return 0;
}
