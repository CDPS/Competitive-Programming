#include <bits/stdc++.h>

using namespace std;

int a[3];
int main(){
    while(scanf("%d %d %d",&a[0],&a[1],&a[2])){
        if(a[0]==0 && a[1]==0 && a[2]==0)
            break;
        sort(a,a+3);
        if(a[2]*a[2] == (a[0]*a[0])+ (a[1]*a[1]) ) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
