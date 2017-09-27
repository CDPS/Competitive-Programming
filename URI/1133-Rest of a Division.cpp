#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,m;

    scanf("%d",&n);
    scanf("%d",&m);

    if(n>m)
        swap(n,m);

    for(int i=n+1;i<m;i++){
        if(i%5==2 || i%5==3)
            printf("%d\n",i);
    }
    return 0;
}
