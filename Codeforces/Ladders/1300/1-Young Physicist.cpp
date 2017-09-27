#include <bits/stdc++.h>

using namespace std;


int main(){
    int x,y,z;
    int xa=0, ya=0, za=0;

    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&x,&y,&z);
        xa+=x;
        ya+=y;
        za+=z;
    }j
    if(xa==0 && ya==0 && za==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
