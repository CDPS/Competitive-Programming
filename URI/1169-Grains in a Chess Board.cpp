#include <bits/stdc++.h>

using namespace std;


unsigned long long power(int x){

    unsigned long long res=1;
    for(int i=0;i<x;i++){
        res*=2;
    }
    return res;
}

int main(){

    int t;
    scanf("%d",&t);

    int x;
    while(t--){

        scanf("%d",&x);

        unsigned long long d= power(x);

        unsigned long long res= d/12;

        res/=1000;

        if(x==64)
         printf("1537228672809129 kg\n");
        else
         printf("%llu kg\n",res);
    }

    return 0;
}
