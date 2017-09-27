#include <bits/stdc++.h>

using namespace std;


int main(){

    int a,n;
    scanf("%d",&a);

    while(true){

        scanf("%d",&n);
        if(n>0)
            break;
    }

    int res=0;
    for(int i=a;i<a+n;i++){
        res+=i;
    }
    printf("%d\n",res);
    return 0;
}
