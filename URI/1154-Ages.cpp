#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,total=0,d=0;

    while(true){

        scanf("%d",&n);

        if(n<0)
            break;
        else{
            total+=n;
            d++;
        }
    }

    printf("%.2lf\n",(double)total/(double)d);
    return 0;
}
