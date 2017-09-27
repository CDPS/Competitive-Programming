#include <bits/stdc++.h>

using namespace std;

int GCD(int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main(){

    int t;

    scanf("%d",&t);

    int f1,f2;
    while(t--){

        scanf("%d %d",&f1,&f2);

        if(f2>f1)
            swap(f1,f2);
        int res = GCD(f1,f2);
        printf("%d\n",res);
    }

    return 0;
}
